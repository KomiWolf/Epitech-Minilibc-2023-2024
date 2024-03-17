BITS 64

SECTION .text
    GLOBAL strncmp

strncmp:
    XOR R10, R10
    .for:
        MOV R8B, BYTE [RDI + R10] ; Stocke le caractère du string dans RDI à l'index RDX dans R8B
        MOV R9B, BYTE [RSI + R10] ; Stocke le caractère du string dans RSI à l'index RDX dans R9B
        CMP RDX, R10
        JE .ret_null ; Saute vers .ret_null si R10 vaut RDX l'int donné en 3eme paramètre de strncmp
        CMP R8B, R9B
        JNE .ret_diff ; Saute vers .ret_diff si R8B et R9B ne sont pas égaux
        CMP R8B, 0
        JE .ret_diff
        CMP R9B, 0
        JE .ret_diff ; Saute vers .ret_equ si les 2 string ont atteint '\0'
        INC R10 ; Incrémente RDX
        JMP .for ; Recommence la boucle
    .ret_diff:
        MOVZX RAX, R8B ; Stocke R8B dans RAX
        MOVZX RBX, R9B ; Stocke R9B dans RBX
        SUB RAX, RBX ; Fait la différence entre RAX et RBX
        RET
    .ret_null:
        MOV RAX, 0
        RET
