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
    MOV AH, 1
    MOV SI, -1
    
LBL_read:
    INC SI
    INT 21h
    MOV str[SI], AL 
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
    

    ; transformare minuscule in majuscule
    MOV SI, 0
    
LBL_transform:
    CMP str[SI], '$'
    JE LBL_fin
    
    MOV AL, str[SI]
    SUB AL, 32
    MOV str[SI], AL
    
    INC SI
    JMP LBL_transform
    
     
LBL_fin:    
    
    
    ; afisare str
    MOV AH, 9
    LEA DX, str
    INT 21h
    
    MOV AH, 4Ch
    int 21h
    
    
    ;.EXIT
    
         
ret
main endp
end
