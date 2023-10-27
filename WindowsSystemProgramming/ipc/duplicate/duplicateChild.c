#include <tchar.h>
#include <Windows.h>

int _tmain(int argc, TCHAR* argv[]) {
	HANDLE hParent = (HANDLE)_ttoi(argv[1]);
	DWORD isSuccess = WaitForSingleObject(hParent, INFINITE);

	_tprintf(_T("child.\n"));
	if (isSuccess == WAIT_FAILED) {
		_tprintf(_T("wait failed.\n"));
		Sleep(10000);
		return -1;
	}
	else {
		_tprintf(_T("Hi~ success..\n"));
		Sleep(10000);
		return 0;
	}
}