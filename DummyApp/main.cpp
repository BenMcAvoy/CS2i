#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

// Custom WndProc
LRESULT WINAPI WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg) {
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

	// say hello in the middle of the screen
	case WM_PAINT: {
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		RECT rect;
		GetClientRect(hWnd, &rect);
		FillRect(hdc, &rect, (HBRUSH)(COLOR_WINDOW + 1));
		const wchar_t* text = L"Hello, World!";
		TextOut(hdc, 16, 16, text, lstrlenW(text));
		EndPaint(hWnd, &ps);
		return 0;
	}
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
	WNDCLASS wc = {};
	wc.lpfnWndProc = WindowProc;
	wc.hInstance = hInstance;
	wc.lpszClassName = L"DummyWindowClass";
	RegisterClass(&wc);

	HWND hWnd = CreateWindowEx(
		0,
		L"DummyWindowClass",
		L"Dummy Window",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 280, 80,
		NULL, NULL, hInstance, NULL
	);

	ShowWindow(hWnd, nShowCmd);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);

		if (msg.message == WM_QUIT) {
			break;
		}
	}

	return 0;
}
