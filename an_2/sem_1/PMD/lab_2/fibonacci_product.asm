org 100h
name program
.model small


.data
    ; calculeaza si afiseza produsul primilor n termeni ai sirului lui Fibonacci
    ; ( incepand cu al doilea, primul fiind 0 )
    
    x db 1
    y db 1
    z db ?  ; next term
    
    p db 1  ; product
    
    n db 6
    
    fd db ? ; first digit
    sd db ? ; second digit
    td db ? ; third digit
    
    rem db ?; remainder
    
.code
	

main proc
   
   MOV AX, @data
   MOV DS, AX
   
   ; clear AX
   MOV AX, 0
   
   MOV CL, n
   
   LBL_PROD:

        MOV AL, x
        ADD AL, y
        
        MOV z, AL   ; z = x + y
        
        MOV AL, p
        MUL x
        MOV p, AL   ; p *= x
        
        MOV BL, y
        MOV x, BL   ; x = y
        
        MOV BL, z
        MOV y, BL   ; y = z
   
    LOOP LBL_PROD
    
    ; display product
     
    MOV AL, p 
    
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
