BITS 64

SECTION .text
    GLOBAL memcpy

memcpy:
    XOR R8, R8
    XOR R9, R9
    .copy_loop:
        CMP R8, RDX
        JE .replace_loop ; Si R8 a atteint la longueur maximale, saute vers .replace_loop
        MOV AL, [RSI] ; Stocke la valeur de l'emplacement actuel de RSI vers AL
        MOV [RDI], AL ; Stocke AL vers l'emplacement actuel de RDI
        INC R8 ; Incrémente R8
        INC RSI ; Incrémente RSI
        INC RDI ; Incrémente RDI
        JMP .copy_loop
    .replace_loop:
        CMP R8, R9
        JE .ret_array ; Si R8 a atteint 0 alors saute vers .ret_array
        DEC R8 ; Décrémente R8
        DEC RDI ; Décrémente RDI
        JMP .replace_loop
    .ret_array:
        MOV RAX, RDI ; Stocke RDI dans RAX
        RET
