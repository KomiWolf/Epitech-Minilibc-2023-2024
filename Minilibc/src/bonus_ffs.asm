BITS 64

SECTION .text
    GLOBAL ffs

ffs:
    XOR R8, R8
    MOV RAX, RDI
    MOV EBX, 2
    .div_loop:
        CMP RAX, 0
        JE .ret_zero
        DIV EBX
        INC R8
        CMP RDX, 1
        JE .ret_value
        JMP .div_loop
    .ret_value:
        MOV RAX, R8
        RET
    .ret_zero:
        MOV RAX, 0
        RET
