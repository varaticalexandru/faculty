org 100h
name program
.model small


.data
    str db 255 dup('$')
    
	

.code
	

main proc
    MOV AX, @data
    MOV DS, AX
    
    MOV AX, 0	; clear AX
    
    ; citire str
    MOV SI, 0
    MOV AH, 1
    
    LBL_read:
        int 21h
        CMP AL, 13
        JE LBL_terminator
        
        MOV str[SI], AL
        INC SI
        JMP LBL_read
        
    
        
    ; seteaza terminatorul de sir ($)    
    LBL_terminator:
        MOV str[SI], '$'
    
    
    MOV AX, 0	; clear AX
    
    
    ; afisare newl + cret
    MOV AH, 2
    MOV DL, 10
    int 21h
    MOV DL, 13
    int 21h
    
    MOV AX, 0	; clear AX
    
        
    ; afisare str
    MOV AH, 9
    LEA DX, str
    int 21h
    
        
        
        
    MOV AH, 4Ch
    int 21h
        
        
    
    
         
ret
main endp
end
