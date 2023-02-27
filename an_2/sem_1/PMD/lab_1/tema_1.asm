org 100h
name program
.model small


.data
    A db ?
    B db ?
    C db ?

.code
main proc
    mov ax, @data
    mov dx, ax
    
    ; read A
    mov ah, 1
    int 21h
    sub al, 30h
    mov A, al
    
    ; print newl+cret
    mov ah, 2
    mov dl, 10
    int 21h
    mov dl, 13
    int 21h
    
    ; read B
    mov ah, 1
    int 21h
    sub al, 30h
    mov B, al
    
    ; print newl+cret
    mov ah, 2
    mov dl, 10
    int 21h
    mov dl, 13
    int 21h
    
    ; read C
    mov ah, 1
    int 21h
    sub al, 30h
    mov C, al
    
    ; print newl+cret
    mov ah, 2
    mov dl, 10
    int 21h
    mov dl, 13
    int 21h
    
    ; A+B-C
    mov al, A
    add al, B
    sub al, C
    
    ; print result
    mov ah, 2
    mov dl, al
    add dl, 30h
    int 21h
    
ret
main endp
end
