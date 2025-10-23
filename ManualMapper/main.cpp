#include "injection.h"

#include "vendor/xorstr.h"
#include "vendor/args.hxx"

// Raise a warning if compiling in debug, since this will typically mismatch the target process and crash
#ifdef _DEBUG
#pragma message("Warning: Compiling in debug mode may cause injection to fail due to architecture mismatch.")
#endif

bool Equals(WCHAR* a, std::string_view b);
DWORD GetProcID(std::string_view procName) {
	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hSnap == INVALID_HANDLE_VALUE) {
		LERR(xorstr_("CreateToolhelp32Snapshot failed. Error: ") << GetLastError());
		return 0;
	}

	PROCESSENTRY32 procEntry;
	procEntry.dwSize = sizeof(PROCESSENTRY32);
	if (!Process32First(hSnap, &procEntry)) {
		LERR(xorstr_("Process32First failed. Error: ") << GetLastError());
		CloseHandle(hSnap);
		return 0;
	}

	do {
		if (Equals(procEntry.szExeFile, procName)) {
			DWORD pid = procEntry.th32ProcessID;
			CloseHandle(hSnap);
			return pid;
		}
	} while (Process32Next(hSnap, &procEntry));

	CloseHandle(hSnap);
	return 0;
}

bool Equals(WCHAR* a, std::string_view b) {
	size_t len = wcslen(a);
	if (len != b.length()) return false;
	for (size_t i = 0; i < len; i++) {
		if (towlower(a[i]) != tolower(b[i])) return false;
	}
	return true;
}

int main(int argc, char* argv[]) {
	args::ArgumentParser parser(xorstr_("Manual DLL Mapper"));
	args::HelpFlag helpFlag(parser, xorstr_("help"), xorstr_("Display this help menu"), { 'h', xorstr_("help") });
	args::CompletionFlag completionFlag(parser, { xorstr_("complete") });

	args::Group injectionGroup(parser, xorstr_("Injection Options"));
	args::ValueFlag<std::string> processNameFlag(injectionGroup, xorstr_("process"), xorstr_("Name of the target process"), { 'p', xorstr_("process") }, xorstr_("DummyApp.exe"));
	args::ValueFlag<std::string> dllPathFlag(injectionGroup, xorstr_("dll"), xorstr_("Path to the DLL to inject"), { 'd', xorstr_("dll") }, xorstr_("DummyDLL.dll"));
	args::Flag targetDirFlag(injectionGroup, xorstr_("targetdir"), xorstr_("Go backwards automatically to find the target directory"), { 't', xorstr_("targetdir") });

	try {
		parser.ParseCLI(argc, argv);
	} catch (const args::Completion& e) {
        std::cout << e.what();
        return 0;
    } catch (const args::Help&) {
        std::cout << parser;
        return 0;
    } catch (const args::ParseError& e) {
		std::cerr << e.what() << std::endl;
		std::cerr << parser;
		return 1;
	}

	std::string processName = processNameFlag.Get();
	DWORD pid = GetProcID(processName);
	if (!pid) {
		LERR(xorstr_("Could not find process ") << processNameFlag.Get());
		return 1;
	}

	LINF(xorstr_("Found process ") << processName << xorstr_(" with PID ") << pid);

	HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
	if (!hProc || hProc == INVALID_HANDLE_VALUE) {
		LERR(xorstr_("OpenProcess failed. Error: ") << GetLastError());
		return 1;
	}

	if (targetDirFlag.Get()) {
		auto target =
#ifdef _DEBUG
			xorstr_("Debug")
#else
			xorstr_("Release")
#endif
			;

		auto dir = std::format("..\\x64\\{}\\", (std::string)target);
		std::filesystem::current_path(dir);
	}

	std::string dllPath = dllPathFlag.Get();
	auto absPath = std::filesystem::absolute(dllPath).string();
	manualMap(hProc, absPath);
}