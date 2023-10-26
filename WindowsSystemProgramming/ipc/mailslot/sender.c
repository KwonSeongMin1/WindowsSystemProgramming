#include <tchar.h>
#include <Windows.h>

#define SLOT_NAME _T("\\\\.\\mailslot\\mailbox")

int _tmain(int argc, LPTSTR argv[]) {
	HANDLE hMailSlot;
	TCHAR message[50];
	DWORD bytesWritten;

	hMailSlot = CreateFile(
		SLOT_NAME,
		GENERIC_WRITE,
		FILE_SHARE_READ,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL
	);
	while (1) {

		// 입력
		_fputts(_T("MY CMD>"), stdout);
		_fgetts(message, sizeof(message) / sizeof(TCHAR), stdin);

		// mailslot 찾지 못하면?
		if (!WriteFile(hMailSlot, message, sizeof(TCHAR) * 50, &bytesWritten, NULL)) {
			_fputts(_T("Unable to write!"), stdout);
			CloseHandle(hMailSlot);
			return 1;
		}

		if (!_tcscmp(message, _T("exit\n"))) {
			_fputts(_T("Good Bye!"), stdout);
			CloseHandle(hMailSlot);
			break;
		}
	}
	return 0;
}