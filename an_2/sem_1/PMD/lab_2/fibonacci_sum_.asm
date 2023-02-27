org 100h
name program
.model small


.data
    ; calculeaza si afiseaza suma primilor n termeni ai seriei lui Fibonacci
    
    n db 8
    
    x db 0
    y db 1
    z db ?  ; new term
    
    s db 0  ; sum
    
    fd db ? ; first digit
    sd db ? ; second digit
    td db ? ; third digit
    
    rem db ?; remainder
    
	

.code
	

main proc
    MOV AX, @data
    MOV DS, AX
    
    MOV AX, 0	; clear AX
    
    MOV CL, n
    
    LBL_SUM:
    
        MOV AL, x
        ADD AL, y          
        
        MOV z, AL   ; z = x + y
        
        MOV AL, s
        ADD AL, x   
        MOV s, AL   ; s += x
        
        MOV BL, y
        MOV x, BL   ; x = y
        
        MOV BL, z
        MOV y, BL   ; y = z
        
        
    LOOP LBL_SUM
    
    
    ; display sum
     
    MOV AL, s 
    
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
