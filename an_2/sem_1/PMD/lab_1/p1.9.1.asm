org 100h
name program
.model small
  
; afiseaza primii 7 termeni din seria Fibonacci

.data
    a db 0
    b db 1
    c db 1
    nl db 10
    cr db 13
    bias db 30h
    
	

.code	
main proc
    mov ax, @data
    mov ds, ax
    
    ; afiseaza a
    mov al, a
    add al, bias
    
    mov ah, 2
    mov dl, al
    int 21h
    
    ; afiseaza newl
    mov ah, 2
    mov dl, nl
    int 21h
    
    mov ah, 2
    mov dl, cr
    int 21h 
    
    ; afiseaza b
    mov al, b
    add al, bias
    
    mov ah, 2
    mov dl, al
    int 21h
    
    ; afiseaza newl
    mov ah, 2
    mov dl, nl
    int 21h
    
    mov ah, 2
    mov dl, cr
    int 21h 
    
    ; afiseaza c
    mov al, c
    add al, bias
    
    mov ah, 2
    mov dl, al
    int 21h
    
    ; afiseaza newl
    mov ah, 2
    mov dl, nl
    int 21h         
     
    mov ah, 2
    mov dl, cr
    int 21h 
    
    ; suma 1+1 = 2         
    mov al, b
    add al, c
    mov a, al ; a=2
    add al, bias
    
    mov ah, 2
    mov dl, al
    int 21h
    
    ; afiseaza newl
    mov ah, 2
    mov dl, nl
    int 21h
    
    mov ah, 2
    mov dl, cr
    int 21h
    
    ; suma 2+1 = 3
    mov al, a
    add al, b
    mov b, al ; b=3
    add al, bias
    
    mov ah, 2
    mov dl, al
    int 21h
    
    ; afiseaza newl
    mov ah, 2
    mov dl, nl
    int 21h
    
    mov ah, 2
    mov dl, cr
    int 21h
    
    ; suma 3+2 = 5
    mov al, a
    add al, b
    mov c, al ; c=5
    add al, bias
    
    mov ah, 2
    mov dl, al
    int 21h
    
    ; afiseaza newl
    mov ah, 2
    mov dl, nl
    int 21h
    
    mov ah, 2
    mov dl, cr
    int 21h
    
    ; suma 5+3 = 8
    mov al, c
    add al, b
    mov a, al ; a=8
    add al, bias
    
    mov ah, 2
    mov dl, al
    int 21h
    
    ; afiseaza newl
    mov ah, 2
    mov dl, nl
    int 21h
    
    mov ah, 2
    mov dl, cr
    int 21h
    
ret
main endp
end
