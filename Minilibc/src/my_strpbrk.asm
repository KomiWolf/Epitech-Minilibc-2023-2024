BITS 64

SECTION .text
    GLOBAL strpbrk

strpbrk:
    XOR RDX, RDX
    XOR RCX, RCX
    XOR R8, R8
    XOR R9, R9
    .loop_in_str:
        MOV RCX, R8 ; Restaure RCX à 0
        MOV AL, BYTE [RDI + RDX] ; Stocke le caractère du string RDI à l'index RDX dans AL
        CMP AL, 0
        JE .ret_null ; Si la première occurence parmi les caractères acceptés n'a pas été trouvé dans le string, alors saute vers .ret_null
        INC RDX ; Incrémente RDX
        JMP .loop_in_accept
    .loop_in_accept:
        MOV BL, BYTE [RSI + RCX] ; Stocke le caractère du string RSI à l'index RCX dans BL
        CMP BL, 0
        JE .loop_in_str ; Si l'occurence n'a pas été trouvé dans le string RDI, alors retourne dans .loop_in_str
        CMP AL, BL
        JE .ret_str ; Si l'occurence a été trouvé, alors saute vers .ret_str
        INC RCX ; Incrémente RCX
        JMP .loop_in_accept
    .ret_str:
        DEC RDX ; Décrémente RDX
        MOV RAX, RDI ; Stocke le string RDI dans RAX
        ADD RAX, RDX ; Déplace le string vers la première occurence
        RET
    .ret_null:
        MOV RAX, 0
        RET
