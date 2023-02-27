org 100h
name program
.model small


.data
    A db ?
	

.code
main proc
    mov ax, @data
    mov ds, ax
    
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
    
    
    ; A+A+A
    mov al, A
    add al, A
    add al, A
    
    ; print result
    mov ah, 2
    mov dl, al
    add dl, 30h
    int 21h
    


ret
main endp
end
