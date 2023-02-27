org 100h
name program
.model small

.data
    A db ?
    B db ?
    C db ?
    D db ?
    
    nl db 10
    cr db 13
    
    bias db 48	

.code
	

main proc
    mov ax, @data
    mov dx, ax
    
    ; read A
    mov ah, 1
    int 21h
    sub al, bias
    mov A, al
    
    ; print nl+cr
    mov dl, nl
    mov ah, 2
    int 21h
    
    mov dl, cr
    mov ah, 2
    int 21h
    
    ; read B
    mov ah, 1
    int 21h
    sub al, bias
    mov B, al
    
    ; print nl+cr
    mov dl, nl
    mov ah, 2
    int 21h
    
    mov dl, cr
    mov ah, 2
    int 21h
    
    ; read C
    mov ah, 1
    int 21h
    sub al, bias
    mov C, al
    
    ; print nl+cr
    mov dl, nl
    mov ah, 2
    int 21h
    
    mov dl, cr
    mov ah, 2
    int 21h
    
    ; read D
    mov ah, 1
    int 21h
    sub al, bias
    mov D, al
    
    ; print nl+cr
    mov dl, nl
    mov ah, 2
    int 21h
    
    mov dl, cr
    mov ah, 2
    int 21h
    
    ; A+D-B+C
    mov al, A
    add al, D
    add al, C
    sub al, B
    
    ; print result
    mov ah, 2
    mov dl, al
    add dl, bias
    int 21h
    
    


ret
main endp
end
