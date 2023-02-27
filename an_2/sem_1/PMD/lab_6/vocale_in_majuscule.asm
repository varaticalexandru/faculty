org 100h
name program
.model small


.data
    str db 255 dup('$')
    
    
	
.code
	

main proc
    MOV AX, @data
    MOV DS, AX
    
    MOV AX, 0	; clear AX
    
    ; citire str
    MOV SI, 0
    MOV AH, 1
    
    LBL_read:
        int 21h
        CMP AL, 13
        JE LBL_terminator
        
        MOV str[SI], AL
        INC SI
        JMP LBL_read    
        
    ; setare terminator de sir    
    LBL_terminator:
        MOV str[SI], '$'
    
        
    ; newl + cret
    MOV AH, 2
    MOV DL, 10
    int 21h
    MOV DL, 13
    int 21h
    
        
        
    ; traversare str
    
    MOV SI, 0
    
    LBL_traverse:
        
        ; iese din bucla
        CMP str[SI], '$'
        JE LBL_exit_traverse
        
        ; if str[SI] = vocala
        CMP str[SI], 'a'
        JE LBL_transform
        
        CMP str[SI], 'e'
        JE LBL_transform
        
        CMP str[SI], 'i'
        JE LBL_transform
        
        CMP str[SI], 'o'
        JE LBL_transform
        
        CMP str[SI], 'u'
        JE LBL_transform
        
        CMP str[SI], 'y'
        JE LBL_transform
        
        ; reia bucla
        INC SI
        JMP LBL_traverse
        
        
        LBL_transform:
            SUB str[SI], 32
            INC SI
            JMP LBL_traverse
            
            
     LBL_exit_traverse:
     
     ; afisare str
     LEA DX, str
     MOV AH, 9
     int 21h
     
     
     MOV AH, 4Ch
     int 21h   
    
    
        
        
         
ret
main endp
end
