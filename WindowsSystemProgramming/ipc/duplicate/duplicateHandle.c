#include <Windows.h>
#include <tchar.h>

int _tmain(int argc, TCHAR* argv[]) {
	HANDLE hProcess;
	TCHAR command[1024];
	DuplicateHandle(
		GetCurrentProcess(),	// �� ���μ�����
		GetCurrentProcess(),	// �� �ڵ���
		GetCurrentProcess(),	// �� ���μ��� �ڵ鿡 �����ض�
		&hProcess,
		0,
		TRUE,
		DUPLICATE_SAME_ACCESS
	);

	_stprintf(command, 
		_T("%s %u"), 
		_T("C:\\Users\\smin9\\OneDrive\\���� ȭ��\\WindowsSystemProgramming\\WindowsSystemProgramming\\ipc\\duplicateChild.exe"), 
		(unsigned)hProcess
	);

	STARTUPINFO si = { 0, };
	PROCESS_INFORMATION pi = { 0, };
	si.cb = sizeof(si);

	BOOL isSuccess = CreateProcess(
		NULL,
		command,
		NULL,
		NULL,
		TRUE,	// ��� �κ�
		CREATE_NEW_CONSOLE,
		NULL,
		NULL,
		&si,
		&pi
	);
	if (!isSuccess) {
		DWORD error = GetLastError();
		_fputts(_T("can't open exe, error code : "), stdout);
		_tprintf(_T("%d\n"), error);
		return -1;
	}

	CloseHandle(pi.hProcess);
	CloseHandle(pi.hProcess);

	_tprintf(_T("parent.\n"));
	_tprintf(_T("parent's handle : %d\n"),hProcess);
	return 0;
}