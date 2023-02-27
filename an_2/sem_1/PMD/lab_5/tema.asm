org 100h
name program
.model small


.data
    s db 255 dup('$')
    s_len db ?
    pref db 255 dup('$'}
    flag db ?
    
    ;
    
    
    
	

.code
	

main proc
    MOV AX, @data
    MOV DS, AX
    
    MOV AX, 0	; clear AX
    
    ; read s
    MOV AH, 1
    MOV SI, 0
    
    LBL_read_s:
        int 21h
        CMP AL, 13
        JE LBL_terminator_s 
        
        MOV s[SI], AL
        INC SI
        JMP LBL_read_s
    
    LBL_terminator_s:
        MOV AL, '$'
        MOV s[SI], AL
        
    MOV AX, 0	; clear AX
    
    ; newl + cret
    MOV AH, 2
    MOV DL, 10
    int 21h
    
    MOV DL, 13
    int 21h 
    
    
    MOV AX, 0	; clear AX
    
    
    ; read pref
    
    MOV AH, 1
    MOV SI, 0
    
    LBL_read_pref:
        int 21h
        CMP AL, 13
        JE LBL_terminator_pref
        
        MOV pref[SI], AL
        INC SI
        JMP LBL_read_pref
    
    
    
    LBL_terminator_pref:
        MOV AL, '$'
        MOV pref[SI], AL
        
        
    ; newl + cret
    MOV AH, 2
    MOV DL, 10
    int 21h
    
    MOV DL, 13
    int 21h
    
    
    ; compare s, pref
    
    MOV SI, 0
    
    LBL_cmp:
    
        CMP pref[SI], '$'
        JE LBL_true
        
        MOV AL, s[SI]
        CMP AL, pref[SI]
        JNE LBL_false
        
        
        INC SI
        JMP LBL_cmp
        
    LBL_true:
        MOV flag, 1
        JMP LBL_fin 
        
        
    LBL_false:
        MOV flag, 0
    
        
        
    LBL_fin:
        MOV DL, flag
        ADD DL, 48
        MOV AH, 2
        int 21h       
    
    
    
    MOV AH, 4Ch
    int 21h
    
         
ret
main endp
end
