#include <Windows.h>
#include <tchar.h>

int _tmain(int argc, TCHAR* argv[]) {
    HANDLE hProcess;
    HANDLE hReadPipe, hWritePipe;
    DWORD bytesRead, bytesWrite;
    TCHAR command[] = _T("C:\\Users\\smin9\\OneDrive\\바탕 화면\\WindowsSystemProgramming\\WindowsSystemProgramming\\ipc\\namelessPipe\\namelessPipeChild.exe");
    TCHAR sendMessage[] = _T("it's test.");

    SECURITY_ATTRIBUTES saAttr = { 0 };
    saAttr.nLength = sizeof(SECURITY_ATTRIBUTES);
    saAttr.bInheritHandle = TRUE; // 헨들 상속을 가능하게 설정

    // 파이프 생성
    CreatePipe(&hReadPipe, &hWritePipe, &saAttr, 0);

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

    CloseHandle(hWritePipe);
    CloseHandle(hReadPipe);
    CloseHandle(pi.hThread);
    CloseHandle(pi.hProcess);
    return 0;
}
