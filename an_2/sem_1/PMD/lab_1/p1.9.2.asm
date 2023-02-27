org 100h
name program
.model small


.data
   n db 10
   sum db 0
   fd db 0
   sd db 0
   td db 0
   rem db 0
   bias db 48
   

.code
	

main proc
    mov ax, @data
    mov ds, ax
    
    mov cl, n
    mov al, 0
    
    back:
         add al, cl
         loop back
         
    mov ah, 00h
    mov sum, al
    
    mov bl, 100
    div bl
    ; ax / bl => al: quotient (1 digit), ah: remainder (2 digits)
    
    ; move quotient (1 digit) to fd
    mov fd, al
    
    ; move remainder (2 digits) to rem (free ah)
    mov rem, ah
    
    
    ; display first digit
    mov ah, 2
    mov dl, fd
    add dl, bias
    int 21h
        
    
    mov ah, 00h
    mov al, rem     
    mov bl, 10
    div bl 
    ; ax / bl => al : quotient (1 digit), ah: remainder (1 digit)
    
    ; move quotient (1 digit) to sd
    mov sd, al
    
    ; move remainder (1 digit) to td
    mov td, ah
    
    ; display second digit
    mov ah, 2
    mov dl, sd
    add dl, bias
    int 21h
    
    ; display third digit
    mov ah, 2
    mov dl, td
    add dl, bias
    int 21h     


ret
main endp
end
