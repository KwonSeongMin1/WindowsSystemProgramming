#include <tchar.h>
#include <Windows.h>
#include <stdio.h>

#define BUFSIZE 1024

int _tmain(int argc, TCHAR* argv[]) {

	TCHAR value[BUFSIZE];

	if (GetEnvironmentVariable(_T("Good"), value, BUFSIZE) > 0) {
		_tprintf(_T("[%s = %s]\n"), _T("Good"), value);
	}
	if (GetEnvironmentVariable(_T("Not"), value, BUFSIZE) > 0) {
		_tprintf(_T("[%s = %s]\n"), _T("Not"), value);
	}
	if (GetEnvironmentVariable(_T("Hmm..."), value, BUFSIZE) > 0) {
		_tprintf(_T("[%s = %s]\n"), _T("Hmm..."), value);
	}

	Sleep(3000);
	return 0;
}