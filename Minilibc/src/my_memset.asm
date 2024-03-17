BITS 64

SECTION .text
    GLOBAL memset

memset:
    XOR R8, R8
    .for:
        CMP R8, RDX
        JE .ret_array ; Si R8 a atteint la longueur maximale, saute vers .ret_array
        MOV BYTE [RDI + R8], SIL ; Déplace la valeur dans SIL vers l'index du tableau RDI
        INC R8 ; Incrémente R8
        JMP .for
    .ret_array:
        MOV RAX, RDI ; Stocke RDI dans RAX
        RET
