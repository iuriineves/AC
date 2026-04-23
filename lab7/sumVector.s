.data
    vector: .word -1, 5, 1, 1, 4
    length: .byte 5 # number of integers in the vector
    sum:    .word 0  # must contain the sum of all elements in vector

.text
.global _start

_start:
   

    # code for the system call exit(int status):
    li a0, 0          # exit status
    li a7, 93         # syscall number for exiting the program
    ecall
    
