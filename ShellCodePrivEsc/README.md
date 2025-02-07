# Privilege Escalation

Un exemple de shellcode pour élever les privilèges sur un système Windows.

## Fonctionnalités
- Élévation des privilèges avec `AdjustTokenPrivileges`.
- Exécution de shellcode après élévation des privilèges.

## Utilisation
1. Remplacez le shellcode dans le fichier `priv_esc.c` par votre propre shellcode.
2. Compilez le programme avec :
```bash
   gcc priv_esc.c -o priv_esc.exe
```

## Avertissement
Ces shellcodes sont fournis à des fins éducatives uniquement. Ne les utilisez pas à des fins malveillantes.

# Clause de non-responsabilité
Les outils et scripts présentés ici sont fournis à des fins éducatives et informatives. Leur utilisation se fait à vos propres risques. L’auteur·ice ne peut être tenu·e responsable de tout dommage, perte de données ou violation de sécurité résultant de leur utilisation. Veillez à tester ces outils / scripts dans un environnement sécurisé et à respecter les lois et réglementations en vigueur dans votre juridiction. L’utilisation non autorisée de ces outils / scripts peut contrevenir à la législation locale ou internationale.
