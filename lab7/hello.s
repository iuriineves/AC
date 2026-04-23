.data
  msg: .ascii "Hello world! How are you today?\n" 
  # msg: .byte 'H','e','l','l','o',' ','w','o','r','l','d','!','\n'

.text
.global _start

_start:
    # code for the system call “write(int fd, const void *buf, size_t count)”:
    li a0, 1          # file descriptor (stdout is represented by code 1)
    la a1, msg        # message’s address
    
    la t1, msg
    li t2, 0
    
    cicle:
    	lb t3, 0(t1)
    	beqz t3, exit
    	li t4, 'a'
    	blt t3, t4, jump
    	li t4, 'z'
    	blt t4, t3, jump
    	addi t3, t3, -32
    	sb t3, 0(t1)
    	
    	jump: 
    	addi t1, t1, 1
    	addi t2, t2, 1
    	j cicle
    	
    exit:
    mv a2, t2         # message’s length
    li a7, 64         # syscall number for the write operation
    ecall

    # code for the system call “exit(int status)”:
    li a0, 0          # exit status
    li a7, 93         # syscall number for exiting the program
    ecall
    
