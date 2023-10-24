#include <stdio.h>
#include <Windows.h>
#include <tchar.h>

#if defined(_WIN64)
typedef unsigned __int64 UINT_PTR;
#else
typedef unsigned int UINT_PTR;
#endif

UINT CallDistance(UINT a, UINT b) {
	return a - b;
}

int _tmain(void) {
	INT val1 = 10;
	INT val2 = 20;

	_tprintf(_T("Position %d, %d\n"), (UINT)&val1, (UINT)&val2);
	_tprintf(_T("distance : %d\n"), CallDistance((UINT)&val1, (UINT)&val2));
	return 0;
}