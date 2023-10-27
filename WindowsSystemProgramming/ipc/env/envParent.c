#include <Windows.h>
#include <tchar.h>

int _tmain(int argc, TCHAR* argv[]) {

	TCHAR command[] = _T("C:\\Users\\smin9\\OneDrive\\πŸ≈¡ »≠∏È\\WindowsSystemProgramming\\WindowsSystemProgramming\\ipc\\env\\envChild.exe");

	SetEnvironmentVariable(_T("Good"), _T("Morning"));
	SetEnvironmentVariable(_T("Not"), _T("hing"));
	SetEnvironmentVariable(_T("Hmm..."), _T("???"));

	STARTUPINFO si = { 0 };
	PROCESS_INFORMATION pi = { 0 };
	si.cb = sizeof(si);

	CreateProcess(
		NULL,
		command,
		NULL,
		NULL,
		FALSE,
		CREATE_NEW_CONSOLE | CREATE_UNICODE_ENVIRONMENT,
		NULL,
		NULL,
		&si,
		&pi
	);

	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);

	return 0;
}