org 100h
name program
.model small


.data
    arr db 255 dup('$')     ; read words array
    arr_ db 255 dup('$')    ; arr_ copy w//o prefix (first word) 
    pref db 255 dup('$')    ; prefix (first word)
    temp db 20 dup('$')     ; gets each word of arr_ (sequentially) 
    
    n db ?  ; read words number (i/p)
    i db 0  ; matched words counter (o/p)
    off dw ?; arr offset (w/o prefix: first word)
    
	

.code
	

main proc
    MOV AX, @data
    MOV DS, AX
    
    MOV AX, 0	; clear AX
    
    ; read n
    MOV AH, 1
    int 21h
    MOV n, AL
    SUB AL, 48
    MOV n, AL
    
    ; newl + cret
    MOV AH, 2
    MOV DL, 10
    int 21h
    MOV DL, 13
    int 21h
    
    ; newl + cret
    MOV AH, 2
    MOV DL, 10
    int 21h
    MOV DL, 13
    int 21h
    
    MOV AX, 0	; clear AX
    
    MOV CL, n
    MOV SI, 0
    
    
    ; read n strings into arr, adjacent strings delimitated by $
    LBL_loop:
        CMP CL, 0
        JZ LBL_fin_read
        
        LBL_read:   ; reads 1 char
            MOV AH, 1
            int 21h
            CMP AL, 13
            JE LBL_terminator
            
            MOV arr[SI], AL
            INC SI
            JMP LBL_read
              
            
        LBL_terminator:
            MOV arr[SI], '$'
            INC SI
            
        LBL_newl:
            MOV AH, 2
            MOV DL, 10
            int 21h
            MOV DL, 13
            int 21h
            
            
    LOOP LBL_loop
        
        
    LBL_fin_read:
    
    
    MOV AX, 0	; clear AX
    MOV SI, 0
    
    LBL_get_pref:   ; copy first string of arr to pref
        CMP arr[SI], '$'
        JE LBL_fin_get_pref
        
        MOV AL, arr[SI]
        MOV pref[SI], AL
        INC SI
        JMP LBL_get_pref
        
        
        
        
        
    LBL_fin_get_pref:
    
    ; copy arr to arr_ w/o pref (first word)
    MOV DI, 0   ; arr_ iterator
    INC SI
    MOV off, SI
      
    LBL_new_arr:
        MOV AL, arr[SI]
        MOV arr_[DI], AL
        INC SI
        INC DI
        
        
        CMP arr[SI], '$'
        JNE LBL_new_arr 
        
        CMP arr[SI+1], '$'
        JE LBL_new_arr_exit
        
            
        
        JMP LBL_new_arr
        
        
    LBL_new_arr_exit:
    
    
    MOV AX, 0	; clear AX
    MOV SI, 0   ; arr iterator
     
    LBL_traverse:
    
        CMP arr_[SI], '$'
        JE LBL_exit
            
        
        MOV DI, 0   ;  temp iterator
          
        LBL_copy:  
            CMP arr_[SI], '$'
            JE LBL_compare 
            
            MOV AL, arr_[SI]
            MOV temp[DI], AL
            
            INC SI
            INC DI
            
            JMP LBL_copy
        
        
        LBL_compare:
            ; compare temp, pref
    
            MOV DI, 0   ; temp, pref iterator
            
            LBL_cmp:
            
                CMP pref[DI], '$'
                JE LBL_true
                
                MOV AL, temp[DI]
                CMP AL, pref[DI]
                JNE LBL_false
                
                
                INC DI
                JMP LBL_cmp
                
            LBL_true:
                ; newl + cret
                MOV AH, 2
                MOV DL, 10
                int 21h
                MOV DL, 13
                int 21h
                
                ; i++, display temp 
                INC i
                LEA DX,temp
                MOV AH, 9
                int 21h
                
                 
                JMP LBL_fin 
                
                
            LBL_false:
                
            
                
                
            LBL_fin:
            
                ; clear temp
                MOV DI, 0
                LBL_clear_temp:
                    CMP DI, 20
                    JE LBL_exit_clear
                    MOV temp[DI], '$' 
                    
                    INC DI
                    
                    JMP LBL_clear_temp
                    
                
                LBL_exit_clear:
                    
                INC SI
                JMP LBL_traverse 
        
    
    LBL_exit:
    
        
        ; newl + cret
        MOV AH, 2
        MOV DL, 10
        int 21h
        MOV DL, 13
        int 21h
        
        ; newl + cret
        MOV AH, 2
        MOV DL, 10
        int 21h
        MOV DL, 13
        int 21h
        
        ; display i
        MOV DL, i
        ADD DL, 48
        MOV AH, 2
        int 21h
        
    
    
        MOV AH, 4Ch
        int 21h
    
         
ret
main endp
end
