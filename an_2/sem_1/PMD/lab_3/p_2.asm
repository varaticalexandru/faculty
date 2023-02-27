org 100h
name program
.model small


.data
    x db ?
    fx dw ?
    
	fd db ? ; first digit
    sd db ? ; second digit
    td db ? ; third digit
    
    rem db ?; remainder

.code
	

main proc
    MOV AX, @data
    MOV DS, AX
    
    MOV AX, 0	; clear AX
    
    ; f(x) = x^2 + x + 5,       if x - even
    ; f(x) = x^3 - x,           if x - odd
    
    ; read x
    MOV AH, 1
    int 21h
    SUB AL, 30h
    MOV x, AL
    
    ; newl + cret
    MOV AH, 2
    MOV DL, 10
    int 21h
    
    MOV DL, 13
    int 21h
     
    
    MOV AX, 0	; clear AX
    
    
    MOV AL, x
    RCR AL, 1
    
    ; if x - even (CF=0)
    JNC LBL_even
    
    ; x^3 - x
    LBL_ODD:
        MOV AL, x
        MUL x
        MUL x
        SUB AL, x
        JMP LBL_disp
    
    
    ; x^2 + x + 5
    LBL_EVEN:
        MOV AL, x
        MUL x
        ADD AL, x
        ADD AL, 5
  
        
    ; display fx
    LBL_disp:
        MOV fx, AX
        
        MOV AX, 0	; clear AX
        
        MOV AX, fx 
    
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
