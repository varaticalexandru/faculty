org 100h
name program
.model small


.data
    str db 255 dup('$')
    vocale db 255 dup('$')
    
	

.code
	

main proc
    MOV AX, @data
    MOV DS, AX
    
    MOV AX, 0	; clear AX
    
    MOV AH, 1
    MOV SI, 0
    
    ; citire str
    LBL_read:
        INT 21h
        MOV str[SI], AL 
        INC SI
        CMP AL, 13
        JNE LBL_read
        
    MOV AL, '$' ; terminator de sir
    MOV str[SI], AL
        
        
    MOV AX, 0	; clear AX
    
    ; newl + cret
    MOV AH, 2
    MOV DL, 10
    int 21h
    MOV DL, 13
    int 21h
    
    MOV AX, 0	; clear AX
    
    ; parcurgere str
    MOV SI, 0
    MOV DI, 0
    
    LBL_loop:
        CMP str[SI], '$'
        JE LBL_exit
        
        
        LBL_0:
            CMP str[SI], 97
            JNE LBL_1
            MOV vocale[DI], 97
            INC DI
            JMP LBL_fin
        
        
        LBL_1:
            CMP str[SI], 101
            JNE LBL_2
            MOV vocale[DI], 101
            INC DI
            JMP LBL_fin
             
            
        LBL_2:    
            CMP str[SI], 105
            JNE LBL_3
            MOV vocale[DI], 105
            INC DI
            JMP LBL_fin
        
        LBL_3:
            CMP str[SI], 111
            JNE LBL_4
            MOV vocale[DI], 111
            INC DI
            JMP LBL_fin
            
        LBL_4:
            CMP str[SI], 117
            JNE LBL_5
            MOV vocale[DI], 117
            INC DI
            JMP LBL_fin
            
        LBL_5:
            CMP str[SI], 121
            JNE LBL_fin
            MOV vocale[DI], 121
            INC DI
            JMP LBL_fin
            
        LBL_fin:
            INC SI
            JMP LBL_loop
            
            
    LBL_exit:
        ; afisare vocale
        MOV AH, 9
        LEA DX, vocale
        int 21h
        
    
    
    
    
    
    MOV AH, 4Ch
    int 21h
             
ret
main endp
end
