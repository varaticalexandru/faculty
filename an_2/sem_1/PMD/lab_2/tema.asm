org 100h
name program
.model small


.data
    x db 2
    
    fx db ?
    
    s db 0  ; sum
    
	

.code
	

main proc
    MOV AX, @data
    MOV DS, AX
    
    MOV AX, 0	; clear AX
    
    ; f(x) = 
    ;           3x^2 + 6x + 2, if x in [0,2]
    ;           2x^3        ,  if x in [3,5]
    ;           2,          ,  if x >= 6
    
    
    
          
     
    
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
            
            MOV AL, s
            ADD AL, fx
            MOV s, AL
            
            LOOP LBL_SUM
            
        
        LBL_GE3:
        
            ; f(x) = 2x^3
        
            MOV AL, CL
            MUL AL
            MUL CL
            MOV BL, 2
            MUL BL
            MOV fx, AL
            
            MOV AL, s
            ADD AL, fx
            MOV s, AL
            
            LOOP LBL_SUM
            
            
            
            
        LBL_GE0:
        
            ; 3x^2 + 6x + 2
        
            MOV AL, CL
            MUL AL
            MOV BL, 3
            MUL BL
            MOV fx, AL
            
            MOV AL, CL
            
            MOV BL, 6
            MUL BL
            
            ADD AL, fx
            ADD AL, 2
            MOV fx, AL
            
            MOV AL, s
            ADD AL, fx
            MOV s, AL
            
            LOOP LBL_SUM
            
            
               
        
     ADD s, 2
         
ret
main endp
end
