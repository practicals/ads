%macro write 2
   mov edx,%1
   mov esi,%2
   mov edi,1
   mov eax,1
   syscall
%endmacro

%macro read 2
   mov edx,%1
   mov esi,%2
   mov edi,0
   mov eax,0
   syscall
%endmacro

%macro exit 0
   mov eax,60
   syscall
%endmacro

section .data

msg1 db '1.addition',0AH
     db '2.subtraction',0AH
     db '3.multiplication',0AH
     db '4.division',0AH
     db '5.exit',0AH
len1 equ $-msg1     
msg2 db 'enter no1 :'
len2 equ $-msg2
msg3 db 'enter no2 :'
len3 equ $-msg3
msg4 db 'addition is :'
len4 equ $-msg4
msg5 db 'subtraction is :'
len5 equ $-msg5
msg6 db 'multiplication is :'
len6 equ $-msg6
msg7 db 'division is :'
len7 equ $-msg7
msg8 db '',0AH
len8 equ $-msg8


section .bss
num1 resb 3
num2 resb 3
m1 resb 3
m2 resb 3
ch1 resb 3
res resb 3

section .text
global _start
          _start :
        
      switch1: 
      write len8,msg8
      write len1,msg1
      read 3,ch1
      mov bl,[ch1]
      cmp bl,'1'
      je case1
      cmp bl,'2'
      je case2
      cmp bl,'3'
      je case3
      cmp bl,'4'
      je case4

      case1:
      
          write len2,msg2
          read 3,num1
          call accept
          mov [m1],bl
          
          write len3,msg3
          read 3,num1
          call accept 
          mov [m2],bl
          
          mov eax,[m1]
          mov ebx,[m2]
          
          add eax,ebx
          
          mov [res],eax
          
          call display
          write len4,msg4
          write 2,num2
          write len8,msg8
      jmp switch1  
      
      case2:
          write len2,msg2
          read 3,num1
          call accept
          mov [m1],bl
          
          write len3,msg3
          read 3,num1
          call accept 
          mov [m2],bl
          
          mov eax,[m1]
          mov ebx,[m2]
          
          sub eax,ebx
          
          mov [res],eax
          
          call display
          write len5,msg5
          write 2,num2
          write len8,msg8
      jmp switch1 

      case3:
          write len2,msg2
          read 3,num1
          call accept
          mov [m1],bl
          
          write len3,msg3
          read 3,num1
          call accept 
          mov [m2],bl
          
          mov eax,[m1]
          mov ebx,[m2]
          
          mul ebx
          
          mov [res],eax
          
          call display
          write len6,msg6
          write 2,num2
          write len8,msg8
           
      jmp switch1

      case4:
          write len2,msg2
          read 3,num1
          call accept
          mov [m1],bl
          
          write len3,msg3
          read 3,num1
          call accept 
          mov [m2],bl
          
          mov eax,[m1]
          mov ebx,[m2]
          
          div ebx
          
          mov [res],eax
          
          call display
          write len7,msg7
          write 2,num2
          write len8,msg8
           
      jmp switch1
      case5:exit
      
accept:
   mov bl,0
   mov ecx,2
   mov esi,num1
l1:
   shl bl,4
   mov al,[esi]
   cmp al,39h
   jbe l2
   sub al,07h
l2:
   sub al,30h
   add bl,al
   inc esi
   dec ecx
   jnz l1
   
   ret
   
display:
   mov bl,[res]
   mov ecx,2
   mov edi,num2 
l3:
   rol bl,4
   mov al,bl
   and al,0FH
   cmp al,09H
   jbe l4
   add al,07H
l4:
   add al,30H
   mov [edi],al
   inc edi
   dec ecx
   jnz l3

   ret           
