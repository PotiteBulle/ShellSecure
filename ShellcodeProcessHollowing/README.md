# Process Hollowing

Un exemple de technique de "Process Hollowing" pour injecter un shellcode dans un processus légitime.

## Fonctionnalités
- Injection de shellcode dans un processus suspendu.
- Utilisation de `CreateProcess`, `VirtualAllocEx`, et `WriteProcessMemory`.

## Utilisation
1. Remplacez le shellcode dans le fichier `process_hollowing.c` par votre propre shellcode.
2. Compilez le programme avec :
```bash
   gcc process_hollowing.c -o process_hollowing.exe
```

## Avertissement
Ces shellcodes sont fournis à des fins éducatives uniquement. Ne les utilisez pas à des fins malveillantes.

# Clause de non-responsabilité
Les outils et scripts présentés ici sont fournis à des fins éducatives et informatives. Leur utilisation se fait à vos propres risques. L’auteur·ice ne peut être tenu·e responsable de tout dommage, perte de données ou violation de sécurité résultant de leur utilisation. Veillez à tester ces outils / scripts dans un environnement sécurisé et à respecter les lois et réglementations en vigueur dans votre juridiction. L’utilisation non autorisée de ces outils / scripts peut contrevenir à la législation locale ou internationale.