BITS 64

SECTION .text
    GLOBAL strcasecmp

strcasecmp:
    XOR RDX, RDX ; Initialise RDX à 0
    .get_character:
        MOV R8B, BYTE [RDI + RDX] ; Stocke le caractère du string dans RDI à l'index RDX dans R8B
        MOV R9B, BYTE [RSI + RDX] ; Stocke le caractère du string dans RSI à l'index RDX dans R9B
        JMP .verify_end_string

    .verify_end_string:
        CMP R8B, 0
        JE .verify_r9b ; Si le string RDI à atteint '\0', saute vers .verify_r9b
        CMP R9B, 0
        JE .verify_r8b ; Si le string RSI à atteint '\0', saute vers .verify_r8b
        JMP .is_lower

    .verify_r9b:
        CMP R9B, 91
        JGE .ret_diff ; Si le caractère R9B >= 91 ([), saute vers .ret_diff
        CMP R9B, 65
        JGE .to_lower_r9b ; Si le caractère R9B >= 65 (A), saute vers .to_lower_r9b
        JMP .ret_diff

    .verify_r8b:
        CMP R8B, 91
        JGE .ret_diff ; Si le caractère R8B >= 91 ([), saute vers .ret_diff
        CMP R8B, 65
        JGE .to_lower_r8b ; Si le caractère R8B >= 65 (A), saute vers .to_lower_r8b
        JMP .ret_diff

    .to_lower_r9b:
        ADD R9B, 32 ; Mets la lettre dans R9B en minuscule
        JMP .ret_diff

    .to_lower_r8b:
        ADD R8B, 32 ; Mets la lettre dans R8B en minuscule
        JMP .ret_diff

    .is_lower:
        CMP R8B, 123
        JGE .compare ; Si le caractère R8B >= 123 ({), saute vers .compare
        CMP R9B, 123
        JGE .compare ; Si le caractère R9B >= 123 ({), saute vers .compare
        CMP R8B, 97
        JGE .to_upper_r8b ; Si le caractère R8B >= 97 (a), saute vers .to_upper_r8b
        CMP R9B, 97
        JGE .to_upper_r9b ; Si le caractère R9B >= 97 (a), saute vers .to_upper_r9b
        JMP .compare

    .to_upper_r8b:
        SUB R8B, 32 ; Mets la lettre dans R8B en majuscule
        JMP .is_lower

    .to_upper_r9b:
        SUB R9B, 32 ; Mets la lettre dans R9B en majuscule
        JMP .is_lower

    .compare:
        CMP R8B, R9B
        JNE .ret_diff ; Saute vers .ret_diff si R8B et R9B ne sont pas égaux
        INC RDX ; Incrémente RDX
        JMP .get_character ; Retourne vers get_character

    .ret_diff:
        MOVZX RAX, R8B ; Stocke R8B dans RAX
        MOVZX RBX, R9B ; Stocke R9B dans RBX
        SUB RAX, RBX ; Fait la différence entre RAX et RBX
        RET
