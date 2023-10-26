#include <tchar.h>
#include <Windows.h>

int _tmain(int argc, TCHAR* argv[]) {
	STARTUPINFO si = { 0, };
	PROCESS_INFORMATION pi;

	TCHAR command[] = _T("notepad.exe");

	if (CreateProcess(
		NULL,
		command,
		NULL,
		NULL,
		TRUE,
		0,
		NULL,
		NULL,
		&si,
		&pi
	)) {
		WaitForSingleObject(pi.hProcess, INFINITE);
		_tprintf(_T("Terminated.\n"));
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	}
	
	return 0;
}