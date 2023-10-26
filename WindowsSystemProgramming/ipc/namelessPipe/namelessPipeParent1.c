#include <Windows.h>
#include <tchar.h>

int _tmain(int argc, TCHAR* argv[]) {
	HANDLE hProcess, hReadPipe, hWritePipe;
	DWORD bytesRead, bytesWrite;
	TCHAR command[] = _T("C:\\Users\\smin9\\OneDrive\\바탕 화면\\WindowsSystemProgramming\\WindowsSystemProgramming\\ipc\\namelessPipe\\namelessPipeChild.exe");
	TCHAR sendMessage[] = _T("it's test.");
	// 상속


	CreatePipe(&hReadPipe, &hWritePipe, NULL, 0);
	
	// 핸들 상속 허용
	SetHandleInformation(hReadPipe, HANDLE_FLAG_INHERIT, HANDLE_FLAG_INHERIT);

	STARTUPINFO si = { 0 };
	PROCESS_INFORMATION pi = { 0 };
	si.cb = sizeof(si);
	si.hStdInput = hReadPipe;
	si.dwFlags = STARTF_USESTDHANDLES;
	
	_tprintf(_T("hReadPipe : %d\n"), hReadPipe);

	BOOL isSuccess = CreateProcess(
		NULL,
		command,
		NULL,
		NULL,
		TRUE,
		CREATE_NEW_CONSOLE,
		NULL,
		NULL,
		&si,
		&pi
	);

	WriteFile(
		hWritePipe,
		sendMessage,
		sizeof(sendMessage) * sizeof(TCHAR),
		&bytesWrite,
		NULL
	);

	CloseHandle(hReadPipe);
	CloseHandle(hWritePipe);
	return 0;
}