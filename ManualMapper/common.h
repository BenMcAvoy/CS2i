#pragma once

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

#define	LINF(msg) std::cout << GREEN << "[+]" << RESET << " " << msg << std::endl
#define LERR(msg) std::cout << RED << "[-]" << RESET << " " << msg << std::endl
#define LWRN(msg) std::cout << YELLOW << "[!]" << RESET << " " << msg << std::endl

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <TlHelp32.h>

#include <iostream>
#include <fstream>
#include <vector>
#include <filesystem>
#include <format>
#include <cstdint>
#include <algorithm>
#include <string>
#include <string_view>
