#include <tchar.h>
#include <Windows.h>

#define SLOT_NAME _T("\\\\.\\mailslot\\mailbox")

int _tmain(int argc, LPTSTR argv[]) {
	HANDLE hMailSlot;
	TCHAR messageBox[50];
	DWORD bytesRead;

	// mailslot 생성
	hMailSlot = CreateMailslot(SLOT_NAME, 0, MAILSLOT_WAIT_FOREVER, NULL);

	// mailslot 읽기
	while (1) {
		ReadFile(hMailSlot, messageBox, sizeof(TCHAR) * 50, &bytesRead, NULL);
		_tprintf(_T("%s"), messageBox);

		if (!_tcscmp(messageBox, _T("exit"))) {
			CloseHandle(hMailSlot);
			break;
		}
	}
	return 0;	
}