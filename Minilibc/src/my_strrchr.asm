BITS 64

SECTION .text
    GLOBAL strrchr

strrchr:
    XOR RDX, RDX ; Initialise RDX à 0
    XOR R8, R8 ; Initialise R8 à 0
    .increment:
        CMP BYTE [RDI + RDX], 0
        JE .for
        INC RDX
        JMP .increment
    .for:
        CMP BYTE [RDI + RDX], SIL
        JE .ret_string ; SI le caractère à été trouvé, alors saute vers .ret_string
        CMP RDX, R8
        JE .ret_null ; Si le le registre RDX à atteint R8 (qui est à 0) alors saute vers .ret_null
        DEC RDX ; Incrémente la valeur dans le registre RDX
        JMP .for ; Saute au début du label .for
    .ret_string:
        MOV RAX, RDI ; Déplace le string vers le registre RAX
        ADD RAX, RDX ; Déplace le string de n caractère vers la droite
        RET
    .ret_null:
        MOV RAX, 0 ; Déplace un '\0' vers RAX
        RET
