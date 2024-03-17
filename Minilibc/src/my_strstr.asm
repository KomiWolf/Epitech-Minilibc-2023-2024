BITS 64

SECTION .text
    GLOBAL strstr

strstr:
    XOR RDX, RDX ; Utilisé pour tourner dans le string RDI
    XOR RCX, RCX ; Utilisé pour tourner dans le string RSI
    XOR R8, R8 ; Utilisé pour sauvegarder l'emplacement actuel du string RDI
    XOR R9, R9 ; Utilisé pour tourner dans le string RDI sans toucher à son itérateur initial
    XOR R10, R10 ; Utilisé comme constante pour restaurer des valeurs à 0
    CMP BYTE [RSI + RCX], 0
    JE .ret_str
    .loop_in_haystack:
        MOV RCX, R10 ; Restaure RCX à 0
        MOV R8, RDX ; Sauvegarde RDX dans R8
        MOV R9, R10 ; Restaure R9 à 0
        MOV AL, BYTE [RDI + RDX] ; Déplace le début du caractère à comparer dans AL 
        CMP AL, 0
        JE .ret_null ; Si aucun segment de string n'a été trouvé alors saute vers .ret_null
        INC RDX ; Incrémente RDX
        JMP .loop_in_needle ; Saute vers .loop_in_needle
    .loop_in_needle:
        MOV BL, BYTE [RSI + RCX] ; Sauvegarde le caractère de "needle" dans BL
        CMP BL, 0
        JE .ret_str ; Si on a atteint la fin du "needle" alors la première occurence a été trouvé donc on saute vers .ret_str
        MOV R11, R8 ; Stocke R8 dans R11
        ADD R11, R9 ; Ajoute R9 à R11
        CMP BYTE [RDI + R11], BL
        JNE .loop_in_haystack ; Si le caractère dans le "haystack" ne correspond pas avec le caractère dans le "needle", alors on retourne vers .loop_in_haystack
        INC R9 ; Incrémente R9
        INC RCX ; Incrémente RCX
        JMP .loop_in_needle ; Recommence la boucle
    .ret_str:
        MOV RAX, RDI
        ADD RAX, R8
        RET
    .ret_null:
        MOV RAX, 0
        RET
