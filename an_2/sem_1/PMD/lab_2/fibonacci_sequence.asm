org 100h
name program
.model small


.data
    ; calculeaza si afiseaza primii n termeni ai seriei lui Fibonacci
    n db 7
    
    x db 0
    y db 1
    z db ?  ; new term
	

.code
	

main proc
    MOV ax, @data
    MOV ds, ax
    
    MOV AX, 0
    
    MOV CL, n
    
    
    LBL_FIB:
    
        MOV AL, x
        ADD AL, y
        
        MOV z, AL   ; z = x + y
        
        ; display x
        MOV AH, 2
        MOV DL, x
        ADD DL, 30h
        INT 21h
        
        ; display newl + cret
        MOV DL, 10
        INT 21h
        MOV DL, 13
        INT 21h
        
        ; clear AX
        MOV AX, 0
        
        
        MOV BL, y   ; x = y
        MOV x, BL
        
        MOV BL, z   ; y = z
        MOV y, BL
        
        LOOP LBL_FIB
         
ret
main endp
end
