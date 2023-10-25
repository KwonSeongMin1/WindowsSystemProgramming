#include <tchar.h>
#include <Windows.h>

#define DIR_LEN MAX_PATH+1

int _tmain(int argc, TCHAR* argv[]) {

	STARTUPINFO si = { 0, };	// size �ʱ�ȭ
	PROCESS_INFORMATION pi;


	//	process ���� �ʱ�ȭ
	si.cb = sizeof(si);
	si.dwFlags = STARTF_USEPOSITION | STARTF_USESIZE;
	si.dwX = 100;
	si.dwY = 200;
	si.dwXSize = 300;
	si.dwYSize = 200;
	si.lpTitle = _T("Hello~");

	TCHAR command[] = _T("notepad.exe ");
	TCHAR cDir[DIR_LEN];
	BOOL state;

	
	// ���� ���丮 Ȯ��
	GetCurrentDirectory(DIR_LEN, cDir);
	_fputts(cDir, stdout);
	_fputts(_T("\n"), stdout);

	//SetCurrentDirectory(_T("C:\\WinSystem"));

	state = CreateProcess(NULL, command, NULL, NULL, TRUE, CREATE_NEW_CONSOLE,
		NULL, NULL, &si, &pi);

	if (state != 0) {
		_fputts(_T("Create OK!\n"), stdout);
	}
	else {
		_fputts(_T("Create Error.\n"), stdout);
	}
}