#include "..\Headlines\launcher.h"

smart::Launcer::Launcer(std::wstring path_exe, std::wstring title) 
	: path_exe_(std::move(path_exe)), title_(std::move(title)) {
	WorkTitle();
}

HWND smart::Launcer::FindWindowByTitle(const std::wstring& window_title) {
	HWND hwnd = FindWindowW(NULL, window_title.c_str());
	return hwnd;
}

bool smart::Launcer::ActiveWindow(HWND hwnd) {
	if(hwnd == NULL) return false;

	if(IsIconic(hwnd)) {
		ShowWindow(hwnd, SW_RESTORE);
	}

	SetForegroundWindow(hwnd);
	return true;
}

std::wstring smart::Launcer::GetWindowTitle(HWND hwnd) {
	wchar_t title[256];
	GetWindowTextW(hwnd, title, 256);
	return std::wstring(title);
}

void smart::Launcer::WorkTitle() {
	
	HWND existing_window = FindWindowByTitle(title_);

	if(existing_window != NULL) {
		std::wstring full_title = GetWindowTitle(existing_window);

		std::wcout << L"Найдено окно: " << full_title << std::endl;
		std::wcout << L"Активируем окно..." << std::endl;
		if (ActiveWindow(existing_window)) {
			std::wcout << L"Окно активировано!" << std::endl;
		} else {
			std::wcout << L"Не удалось активировать окно!" << std::endl;
		}
	} else {
		std::wcout << L"Окно не найдено. Запускаем программу!" << std::endl;

		PROCESS_INFORMATION process_information = { 0 };
		STARTUPINFO startup_info = { 0 };
		startup_info.cb = sizeof(startup_info);

		std::vector<wchar_t> command_line(path_exe_.begin(), path_exe_.end());
		command_line.push_back(L'\0');

		//DWORD creation_flags = CREATE_NEW_CONSOLE;

		BOOL success = CreateProcessW(
			NULL,
			command_line.data(),
			NULL,
			NULL,
			FALSE,
			0,
			NULL,
			NULL,
			&startup_info,
			&process_information
		);

		if (success) {
			std::wcout << "SUCCESS! PID: " << process_information.dwProcessId << std::endl;
			CloseHandle(process_information.hProcess);
			CloseHandle(process_information.hThread);

		} else {
			DWORD error = GetLastError();
			std::wcout << "ERROR! COD: " << error << std::endl;
		}
	}
}













