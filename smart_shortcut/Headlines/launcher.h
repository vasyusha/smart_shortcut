#include <Windows.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

namespace smart {

class Launcer {
private:
	std::wstring path_exe_;
	std::wstring title_;	
	int id_;
public:
	Launcer(std::wstring path_exe, std::wstring title);

	HWND FindWindowByTitle(const std::wstring& window_title);

	bool ActiveWindow(HWND hwnd);

	std::wstring GetWindowTitle(HWND hwnd);

	void WorkTitle();

};

}

/*


BOOL CreateRegistryKey(HKEY h_key_root, LPCWSTR sub_key) {
	HKEY h_key;
	DWORD discription;
	LONG result = RegCreateKeyExW(
		h_key_root,
		sub_key,
		0,
		NULL,
		REG_OPTION_NON_VOLATILE,
		KEY_ALL_ACCESS,
		NULL,
		&h_key,
		&discription
	);

	if(result == ERROR_SUCCESS) {
		std::wcout << L"Ключ создан успешно: " << sub_key << std::endl;
		RegCloseKey(h_key);
		return TRUE;
	} else {
		std::wcerr << L"Ошибка создания ключа: " << result << std::endl;
		return FALSE;
	}
}

template <typename T>
BOOL SetValue(HKEY h_key_root, LPCWSTR sub_key
	, LPCWSTR value_name, T value_data) {

	HKEY h_key;
	LONG result = RegOpenKeyExW(h_key_root, sub_key, 0, KEY_WRITE, &h_key);

	if(result != ERROR_SUCCESS) {
		std::wcerr << L"Ошибка открытия ключа: " << result << std::endl;
	}

	result = RegSetValueExW(
		h_key,
		value_name,
		0,
		REG_SZ,
		static_cast<const BYTE*>(static_cast<const void*>(value_data)),
		(wcslen(value_data) + 1) * sizeof(WCHAR)
	);

	RegCloseKey(h_key);

	if (result == ERROR_SUCCESS) {
		std::wcout << L"Значение создано успешно: " << value_name << std::endl;
		return TRUE;
	} else {
		std::wcerr << L"Ошибка создания значения: " << result << std::endl;
		return FALSE;
	}
}



*/
