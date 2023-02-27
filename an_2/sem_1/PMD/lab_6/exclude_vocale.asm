org 100h
name program
.model small


.data
    str db 255 dup('$')
    
	

.code
	

main proc
    MOV AX, @data
    MOV DS, AX
    
    ; clear AX
    MOV AX, 0
    
    ; citire str
    MOV AH, 1
    MOV SI, 0
    
    LBL_read:
        int 21h
        CMP AL, 13
        JE LBL_terminator
        
        MOV str[SI], AL
        INC SI
        JMP LBL_read
        
    ; setare terminator de sir    
    LBL_terminator:
        MOV str[SI], '$'
        
    
    ; newl + cret
    MOV AH, 2
    MOV DL, 10
    int 21h
    MOV DL, 13
    int 21h
    
        
    ; traversare sir
    MOV SI, 0
    
    LBL_traverse:
        CMP str[SI], '$'
        JE LBL_exit_traverse
        
        CMP str[SI], 'a'
        JE LBL_exclude
        
        CMP str[SI], 'e'
        JE LBL_exclude
        
        CMP str[SI], 'i'
        JE LBL_exclude
        
        CMP str[SI], 'o'
        JE LBL_exclude
        
        CMP str[SI], 'u'
        JE LBL_exclude
        
        CMP str[SI], 'y'
        JE LBL_exclude
        
        INC SI
        JMP LBL_traverse
        
        LBL_exclude:
            MOV DI, SI
            
            LBL_lshift:
                CMP DI, '$'
                JE LBL_exit_exclude
                
                MOV AL, str[DI+1]
                MOV str[DI], AL;     str[DI] = str[DI+1]
                INC DI
                JMP LBL_lshift
                
                
                
        LBL_exit_exclude:
            JMP LBL_traverse
                
        
        
        
        LBL_exit_traverse:
        
        ; afisare str
        LEA DX, str
        MOV AH, 9
        int 21h
    
    
         
ret
main endp
end
