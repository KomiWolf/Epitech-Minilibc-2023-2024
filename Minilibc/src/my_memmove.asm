BITS 64

SECTION .text
    GLOBAL memmove

memmove:
    XOR R8, R8
    XOR R9, R9
    MOV R9, RDX
    DEC R9
    CMP RDI, RSI
    JAE .backward_loop ; Si RSI est inférieur à RDI alors saute vers .backward_loop
    .forward_loop:
        CMP R8, RDX
        JE .ret_array ; Si R8 a atteint RDX alors saute vers .ret_array
        MOV AL, BYTE [RSI + R8]
        MOV BYTE [RDI + R8], AL
        INC R8
        JMP .forward_loop
    .backward_loop:
        CMP R9, 0
        JL .ret_array ; Si R9 est inférieur à 0 alors saute vers .ret_array
        MOV AL, BYTE [RSI + R9]
        MOV BYTE [RDI + R9], AL
        DEC R9
        JMP .backward_loop
    .ret_array:
        MOV RAX, RDI
        RET
