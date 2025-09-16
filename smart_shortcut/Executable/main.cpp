#include "..\Headlines\launcher.h"

int wmain(int argc, wchar_t* argv[]) {
	setlocale(LC_ALL, "");

	smart::Launcer launcehr(argv[1], argv[2]);
}