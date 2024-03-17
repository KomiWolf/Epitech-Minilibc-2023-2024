BITS 64

SECTION .text
    GLOBAL strlen

strlen:
    MOV RSI, RDI ; Déplace le string contenu dans RDI vers RSI
    XOR RDX, RDX ; Initialise la longueur du string à 0
    .for:
        CMP BYTE [RSI + RDX], 0 ; Vérifie si le caractère actuel est un \0
        JE .end ; Sort de la boucle et va vers le label .end si c'est le cas
        INC RDX ; Sinon, Incrémente le compteur
        JMP .for ; Retourne vers le début de la boucle
    .end:
        MOV RAX, RDX ; Déplace le résultat vers RAX qui sera la valeur de retour
        RET
