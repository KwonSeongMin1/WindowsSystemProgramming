#include <tchar.h>
#include <Windows.h>

int main() {
	STARTUPINFO si = { 0, };
	PROCESS_INFORMATION pi;
	si.cb = sizeof(si);

	// 경로를 알아서 정해주세요
	TCHAR command[] = _T("C:\\Users\\smin9\\OneDrive\\바탕 화면\\WindowsSystemProgramming\\WindowsSystemProgramming\\kernal_object\\test.exe");
	/*TCHAR cDir[MAX_PATH + 1];
	GetCurrentDirectory(MAX_PATH+1, cDir);
	_fputts(cDir, stdout);
	_fputts(_T("\n"), stdout);*/

	BOOL state = CreateProcess(NULL, command, NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi);

	// test code
	if (state != 0) {
		_fputts(_T("Good..!\n"), stdout);
	}
	else {
		DWORD error = GetLastError();
		_fputts(_T("can't open exe, error code : \n"), stdout);
		_tprintf(_T("%d\n"), error);
		return 0;
	}


	while (1) {
		for (DWORD i = 0; i < 10000; i++) {
			for (DWORD i = 0; i < 10000; i++) {
				
			}
			// test.exe -> I'm Chlid.exe repeat
			_fputts(_T("I'm parent.exe\n"), stdout);
		}
	}
	return 0;
}