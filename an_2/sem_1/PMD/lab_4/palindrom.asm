org 100h
name program
.model small


.data
    str db 255 dup('$')
    
    len dw -2
    
    palindrom_0 db 'cuvantul nu este palindrom$'
    palindrom_1 db 'cuvantul este palindrom$'
    

.code
	

main proc
    MOV AX, @data
    MOV DS, AX
    
    MOV AX, 0	; clear AX
    
    ; citire s1
    MOV AH, 1
    MOV SI, 0
    
    LBL_read_1:
        int 21h
        MOV str[SI], AL
        INC SI
        INC len
        CMP AL, 13
        JNE LBL_read_1
        
    MOV AL, '$'
    MOV str[SI], AL
    
    
    
     ; newl + cret
    MOV AH, 2
    MOV DL, 10
    int 21h
    MOV DL, 13
    int 21h
          
          
    MOV AX, 0	; clear AX 
           
    
    MOV SI, 0   ; traverse from str[0]
    MOV DI, len ; traverse backwards from str[len]
            
    LBL_loop:
        MOV AL, str[SI]
        CMP AL, str[DI]
        JNE LBL_false   ; if str[SI] != str[BI]
        
        CMP SI, DI
        JGE LBL_true    ; if SI >= DI     
        
        INC SI
        DEC DI
        JMP LBL_loop
        
    
    ; disp palindrom status
            
    LBL_false:  ; is not palindrom
        LEA DX, palindrom_0
        MOV AH, 9
        int 21h
        JMP LBL_fin
           
    
    LBL_true:   ; is palindrom
        LEA DX, palindrom_1
        MOV AH, 9
        int 21h
        
      
    
    LBL_fin:
        MOV AH, 4Ch
        int 21h  
         
ret
main endp
end
