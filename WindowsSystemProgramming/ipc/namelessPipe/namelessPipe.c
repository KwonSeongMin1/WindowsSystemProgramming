#include <Windows.h>
#include <tchar.h>

int _tmain(int argc, TCHAR* argv[]) {
	HANDLE hReadPipe, hWritePipe;	// createPipe ½Ã Pipe ¾ç ÂÊ

	TCHAR sendMessage[] = _T("Hello???");
	TCHAR recvMessage[100];

	DWORD byteRead;
	DWORD byteWrite;

	CreatePipe(&hReadPipe, &hWritePipe, NULL, 0);

	WriteFile(
		hWritePipe,
		sendMessage,
		sizeof(sendMessage) * sizeof(TCHAR),
		&byteWrite,
		NULL
	);
	ReadFile(
		hReadPipe,
		recvMessage,
		byteWrite,
		&byteRead,
		NULL
	);
	recvMessage[byteRead / sizeof(TCHAR)] = 0;
	_tprintf(_T("recv : %s\n"), recvMessage);

	CloseHandle(hReadPipe);
	CloseHandle(hWritePipe);

	return 0;


}