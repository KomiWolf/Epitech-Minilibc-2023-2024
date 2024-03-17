BITS 64

SECTION .text
    GLOBAL strcspn

strcspn:
    ; Initialise les registres suivants à 0
    XOR RDX, RDX
    XOR RCX, RCX
    XOR R8, R8
    XOR R9, R9

    .loop_in_str:
        MOV RCX, R8 ; Remet RCX à la valeur de R8 (0)
        MOV AL, BYTE [RDI + RDX] ; Stocke le caractère dans RDI dans AL
        CMP AL, 0
        JE .ret_all ; Si le caractère est un '\0', saute vers .ret_all
        INC RDX ; Incrémente RDX, le compteur de RDI
        JMP .loop_in_reject ; Saute vers .loop_in_reject
    .loop_in_reject:
        MOV BL, BYTE [RSI + RCX] ; Stocke le caractère dans RSI dans BL
        CMP BL, 0
        JE .loop_in_str ; Si le caractère n'est pas un caractère rejeté alors retourne vers .loop_in_str
        CMP AL, BL
        JE .find_real_num ; Si le caractère est un caractère rejeté saute vers .find_real_num
        INC RCX ; Incrémente RCX, le compteur de RSI
        JMP .loop_in_reject ; Recommence la boucle .loop_in_reject
    .find_real_num:
        CMP RDX, 1
        JE .ret_num ; Si RDX a atteint 1, saute vers .ret_num
        DEC RDX ; Décrémente RDX
        INC R9 ; Incrémente R9
        JMP .find_real_num ; Recommence la boucle .find_real_num
    .ret_num:
        MOV RAX, R9
        RET
    .ret_all:
        MOV RAX, RDX
        RET
