BITS 64

SECTION .text
    GLOBAL strchr

strchr:
    XOR RDX, RDX ; Initialise RDX à 0
    .for:
        CMP BYTE [RDI + RDX], SIL
        JE .ret_string ; SI le caractère à été trouvé, alors saute vers .ret_string
        CMP BYTE [RDI + RDX], 0
        JE .ret_null ; Si le caractère à atteint '\0' alors saute vers .ret_null
        INC RDX ; Incrémente la valeur dans le registre RDX
        JMP .for ; Saute au début du label .for
    .ret_string:
        MOV RAX, RDI ; Déplace le string vers le registre RAX
        ADD RAX, RDX ; Déplace le string de n caractère vers la droite
        RET
    .ret_null:
        MOV RAX, 0 ; Déplace un '\0' vers RAX
        RET
