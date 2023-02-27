org 100h
name program
.model small


.data    
    x db 4
    
    fx db ?    
    
    fd db ? ; first digit
    sd db ? ; second digit
    td db ? ; third digit
    
    rem db ?; remainder
    
	

.code
	

main proc
    MOV AX, @data
    MOV DS, AX
    
    MOV AX, 0	; clear AX
    
    
    ; f(x) = 
    ;          x^2,     if x - even
    ;          x^3 - 1, if x - odd
    
    
     MOV AL, x
     MOV BL, 2 
     DIV BL      ; AL = x / 2
     
     CMP AH, 0  ; AH = x % 2
     
     JZ LBL_EVEN
     
     LBL_ODD:
        
        ; x^3 - 1
        MOV AL, x
        MUL AL
        MUL x
        SUB AL, 1   
        JMP LBL_DISP
            
     
     LBL_EVEN:
     
        ; x^2
        MOV AL, x
        MUL AL 
        
           
    LBL_DISP:
    
        MOV fx, AL 
        
        ; display 
         
        MOV AL, fx 
        
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
