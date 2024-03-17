BITS 64

SECTION .text
    GLOBAL strcmp

strcmp:
    XOR RDX, RDX ; Initialise RDX à 0
    .for:
        MOV R8B, BYTE [RDI + RDX] ; Stocke le caractère du string dans RDI à l'index RDX dans R8B
        MOV R9B, BYTE [RSI + RDX] ; Stocke le caractère du string dans RSI à l'index RDX dans R9B
        CMP R8B, R9B
        JNE .ret_diff ; Saute vers .ret_diff si R8B et R9B ne sont pas égaux
        CMP R8B, 0
        JE .ret_diff
        CMP R9B, 0
        JE .ret_diff ; Saute vers .ret_equ si l'un des deux string a atteint '\0'
        INC RDX ; Incrémente RDX
        JMP .for ; Recommence la boucle
    .ret_diff:
        MOVZX RAX, R8B ; Stocke R8B dans RAX
        MOVZX RBX, R9B ; Stocke R9B dans RBX
        SUB RAX, RBX ; Fait la différence entre RAX et RBX
        RET
