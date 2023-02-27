org 100h
name program
.model small


.data

    a db 18
    b db 12
    
    a_ db ? ; copy of initial a
    b_ db ? ; copy of initial b
    
    cmmdc db ?  ;; cmmdc
    cmmmc db ?  ;; cmmmc
    
    fd db ? ; first digit
    sd db ? ; second digit
    td db ? ; third digit
    
    rem db ?; remainder

.code
	

main proc
    MOV AX, @data
    MOV DS, AX
    
    MOV AX, 0	; clear AX
    
    ; a_ = a
    MOV AL, a
    MOV a_, AL
    
    ; b_ = b
    MOV AL, b
    MOV b_, AL
    
    
    LBL_WHILE:
        ; while (a!=b)
        MOV AL, a
        CMP AL, b
        
        JE LBL_EXIT
        
        MOV AL, a
        CMP AL, b
        
        JL LBL_LESS
        
        LBL_GREATER:
            ; a = a - b
            MOV AL, a
            SUB AL, b
            MOV a, AL
            JMP LBL_WHILE
        
        LBL_LESS:
            ; b = b - a
            MOV AL, b
            SUB AL, a
            MOV b, AL
            JMP LBL_WHILE
            
        
            
         
    LBL_EXIT:
        MOV AX, 0	; clear AX
        
        ; cmmdc = a
        MOV AL, a
        MOV cmmdc, AL     
        
        ; cmmmc = a*b/cmmdc
        MOV AL, a_
        MUL b_
        DIV cmmdc
        MOV cmmmc, AL
              
              
        LBL_DISP_CMMDC:
             
        ; display cmmdc
        MOV AL, cmmdc 
        
        MOV BL, 100
        DIV BL
        ; ax / bl => al: quotient (1 digit), ah: remainder (2 digits)
        
        ; move quotient (1 digit) to fd
        MOV fd, AL
        
        ; move remainder (2 digits) to rem (free ah)
        MOV rem, AH
        
        ; display first digit
        MOV AH, 2
        MOV DL, fd
        ADD DL, 30h
        int 21h
            
        ; clear AX
        MOV AX, 0
        
        MOV AL, rem     
        MOV BL, 10
        DIV BL 
        ; ax / bl => al : quotient (1 digit), ah: remainder (1 digit)
        
        ; move quotient (1 digit) to sd
        MOV sd, AL
        
        ; move remainder (1 digit) to td
        MOV td, AH
        
        ; display second digit
        MOV AH, 2
        MOV DL, sd
        ADD DL, 30h
        int 21h
        
        ; display third digit
        MOV AH, 2
        MOV DL, td
        ADD DL, 30h
        int 21h
              
              
        
        ; newl + cret
    
        MOV AH, 2
        MOV DL, 10
        int 21h
        
        MOV DL, 13
        int 21h
        
                 
                 
       
        LBL_DISP_CMMMC:
        ; display cmmdc
        
        MOV AX, 0	; clear AX
        
        MOV AL, cmmmc 
        
        MOV BL, 100
        DIV BL
        ; ax / bl => al: quotient (1 digit), ah: remainder (2 digits)
        
        ; move quotient (1 digit) to fd
        MOV fd, AL
        
        ; move remainder (2 digits) to rem (free ah)
        MOV rem, AH
        
        ; display first digit
        MOV AH, 2
        MOV DL, fd
        ADD DL, 30h
        int 21h
            
        ; clear AX
        MOV AX, 0
        
        MOV AL, rem     
        MOV BL, 10
        DIV BL 
        ; ax / bl => al : quotient (1 digit), ah: remainder (1 digit)
        
        ; move quotient (1 digit) to sd
        MOV sd, AL
        
        ; move remainder (1 digit) to td
        MOV td, AH
        
        ; display second digit
        MOV AH, 2
        MOV DL, sd
        ADD DL, 30h
        int 21h
        
        ; display third digit
        MOV AH, 2
        MOV DL, td
        ADD DL, 30h
        int 21h
        
              
    
           
ret
main endp
end
