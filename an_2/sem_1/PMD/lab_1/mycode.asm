name program


.model small

org 100h
.data
    ; A + B - C
    A db 0
    B db 0
    C db 0
    X dw 7
    
.code
	

main proc
    mov ax, @data
    mov ds, ax
    
    mov ah, 1
    int 21h
    mov A, al
    
    mov ah, 1
    int 21h
    mov B, al
    
    mov ah, 1
    int 21h
    mov C, al
    
    mov al, A
    add al, B
    sub al, C
    
    mov ah, 2
    mov dl, al
    int 21h
    

ret
main endp
end
