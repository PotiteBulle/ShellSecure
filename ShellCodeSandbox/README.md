# Sandbox Evasion

Un exemple de shellcode pour détecter et contourner les environnements sandbox.

## Fonctionnalités
- Détection de sandbox basée sur la mémoire disponible.
- Exécution de shellcode si aucun sandbox n'est détecté.

## Utilisation
1. Remplacez le shellcode dans le fichier `sandbox_evasion.c` par votre propre shellcode.
2. Compilez le programme avec :
```bash
   gcc sandbox_evasion.c -o sandbox_evasion.exe
 ```

## Avertissement
Ces shellcodes sont fournis à des fins éducatives uniquement. Ne les utilisez pas à des fins malveillantes.

# Clause de non-responsabilité
Les outils et scripts présentés ici sont fournis à des fins éducatives et informatives. Leur utilisation se fait à vos propres risques. L’auteur·ice ne peut être tenu·e responsable de tout dommage, perte de données ou violation de sécurité résultant de leur utilisation. Veillez à tester ces outils / scripts dans un environnement sécurisé et à respecter les lois et réglementations en vigueur dans votre juridiction. L’utilisation non autorisée de ces outils / scripts peut contrevenir à la législation locale ou internationale.