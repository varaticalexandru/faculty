org 100h
name program
.model small


.data
    msg1 db 255 dup('$')
    msg2 db 255 dup('$')
    msg3 db 255 dup('$')
    
	

.code
	

main proc
    MOV AX, @data
    MOV DS, AX
    
    MOV AX, 0	; clear AX
    
    ; read msg1
    
    MOV AH, 1
    MOV SI, 0
   
    LBL_read_1:
        int 21h
        CMP AL, 13
        JE LBL_end_1
        MOV msg1[SI], AL
        INC SI
        JMP LBL_read_1
    
    ; string terminator
    LBL_end_1:    
        MOV AL, '$'
        MOV msg1[SI], AL
    
    
    MOV AX, 0;  clear AX
    
    ; newl + cret
    MOV AH, 2
    MOV DL, 10
    int 21h
    MOV DL, 13
    int 21h
    
    MOV AX, 0;  clear AX
        
    
    
    ; read msg2
    
    MOV AH, 1    
    MOV SI, 0
    
    LBL_read_2:
        int 21h
        CMP AL, 13
        JE LBL_end_2
        MOV msg2[SI], AL
        INC SI
        JMP LBL_read_2
        
    ; string terminator
    LBL_end_2:
        MOV AL, '$'
        MOV msg2[SI], AL
                  
    
    ; newl + cret
    MOV AH, 2
    MOV DL, 10
    int 21h
    MOV DL, 13
    int 21h
    
    
    ; msg3 = msg1 + msg2
    
    ; msg3 += msg1
    
    MOV SI, 0   ; iterator for msg3
    
    LBL_loop_1:
        MOV AL, msg1[SI]
        MOV msg3[SI], AL
        INC SI
        CMP msg1[SI], '$'
        JNE LBL_loop_1
    
    
     MOV AX, 0  ; clear AX   
        
    ; msg3 += msg2
    
    MOV DI, 0   ; iterator for msg2
    
    LBL_loop_2:
        MOV AL, msg2[DI]
        MOV msg3[SI], AL
        INC SI
        INC DI
        CMP msg2[DI], '$'
        JNE LBL_loop_2
        
    ; string terminator
    ;MOV msg3[SI], '$'
        
        
    ; disp msg3
    LBL_fin:
        MOV AX, 0   ; clear AX
        
        LEA DX, msg3
        MOV AH, 9
        int 21h
    
    
    MOV AH, 4Ch
    int 21h 
    
    
    
         
ret
main endp
end
