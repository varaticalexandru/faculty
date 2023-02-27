org 100h
name program
.model small


.data
    x db ? 
    
    fx dw ?
    
    s dw 0  ; sum
    
    fd db ? ; first digit
    sd db ? ; second digit
    td db ? ; third digit
    
    rem db ?; remainder
    
.code
	

main proc
    
    MOV AX, @data
    MOV DS, AX
    
    ; f(x) = 
    ;           3x^2 + 6x + 2, if x in [0,2]
    ;           2x^3        ,  if x in [3,5]
    ;           2,          ,  if x >= 6
    
    MOV AX, 0	; clear AX
    
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
    
    MOV CL, x
    
    
       
    LBL_SUM:
    
        MOV AL, CL
    
        CMP AL, 6
        JGE LBL_GE6   ; if x >= 6
        
        CMP AL, 3
        JGE LBL_GE3   ; if x >= 3
        
        CMP AL, 0
        JGE LBL_GE0   ; if x >= 0
    
        LBL_GE6:
            
            ; f(x) = 2
        
            MOV fx, 2
            
            MOV AX, s
            ADD AX, fx
            MOV s, AX
            
            LOOP LBL_SUM
            
        
        LBL_GE3:
        
            ; f(x) = 2x^3
        
            MOV AL, CL
            MUL AL
            MUL CL
            
            MOV BL, 2
            MUL BL
            
            MOV fx, AX
            
            MOV AX, s
            ADD AX, fx
            MOV s, AX
            
            LOOP LBL_SUM
            
            
            
            
        LBL_GE0:
        
            ; 3x^2 + 6x + 2
        
            MOV AL, CL
            MUL AL
            
            MOV BL, 3
            MUL BL
            MOV fx, AX
            
            MOV AL, CL
            MOV BL, 6
            MUL BL
            
            ADD AX, fx
            ADD AX, 2
            
            MOV fx, AX
            
            MOV AX, s
            ADD AX, fx
            MOV s, AX
            
            LOOP LBL_SUM
                       
        
     ADD s, 2   ; s += [f(0) = 2]
     
    
    
     
    ; display sum ( max 3 digit )
     
    MOV AX, s 
    
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

