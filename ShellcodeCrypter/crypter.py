import sys
def xor_encrypt_decrypt(shellcode, key):
    """
    Chiffre ou déchiffre un shellcode en utilisant un chiffrement XOR.

    Args:
        shellcode (bytes): Le shellcode à chiffrer/déchiffrer.
        key (bytes): La clé de chiffrement.

    Returns:
        bytes: Le shellcode chiffré/déchiffré.
    """
    return bytes([shellcode[i] ^ key[i % len(key)] for i in range(len(shellcode))])

def main():
    """
    Fonction principale du script.
    """
    # Vérification des arguments de la ligne de commande
    if len(sys.argv) != 4:
        print("Usage: python crypter.py <shellcode_file> <key> <output_file>")
        print("Example: python crypter.py shellcode.bin mykey encrypted_shellcode.bin")
        sys.exit(1)

    # Récupération des arguments
    shellcode_file = sys.argv[1]  # Fichier contenant le shellcode
    key = sys.argv[2].encode()    # Clé de chiffrement (convertie en bytes)
    output_file = sys.argv[3]     # Fichier de sortie pour le shellcode chiffré

    # Lecture du shellcode depuis le fichier
    try:
        with open(shellcode_file, "rb") as f:
            shellcode = f.read()
    except FileNotFoundError:
        print(f"[-] Error: File '{shellcode_file}' not found.")
        sys.exit(1)

    # Chiffrement du shellcode
    encrypted_shellcode = xor_encrypt_decrypt(shellcode, key)

    # Sauvegarde du shellcode chiffré dans le fichier de sortie
    try:
        with open(output_file, "wb") as f:
            f.write(encrypted_shellcode)
        print(f"[+] Shellcode encrypted and saved to '{output_file}'")
    except IOError:
        print(f"[-] Error: Could not write to file '{output_file}'.")
        sys.exit(1)

if __name__ == "__main__":
    main()