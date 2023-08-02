.globl main

.data
arr: .word 0,0,0,0,0,0,0,0,0,0
num: .word 7


.text
main:
    addi s0, x0, 10 # to hold the value of i for the muber of iterations
    la t0, num      # holds the address of the variable num
    lw a0, 0(t0)    # stores the value of num in register a0
    la s5, arr      # stores the address of arr in s5   
    addi t1, x0, 10 # used to print the values from the array
    j dataArray
    
dataArray:
    # checks whether the number of iterations has been completed add decreases the value of i by 1 in every loop
    beq s0, x0, end
    addi s0, s0, -1
    #jumps to the sub function
    jal ra, subt
    #updates the address of the array to store the retrieved value in the correct place in the array
    sw a0, 0(s5)
    addi t6, x0, 4
    add s5, t6, s5
    #pops a0 from the atck
    lw a0, 0(sp)
    addi sp, sp, 4
    j dataArray
    
compare:
    #pushes a0 onto the stack
    addi sp, sp, -4
    sw a0, 0(sp)
    #checks whether the value returned from the sub function is negative or not and returns 0 or 1 accordingly
    blt t5, x0, next
    addi a0, x0, 1
    jr ra
    
next:
    add a0, x0, x0
    jr ra
    
subt:
    #difference of num and i is calculated and returned to the compare function
    add t3, x0, a0
    add t4, x0, s0
    sub t5, t3, t4
    j compare
    
end:
    #copies the values from the array to be stores in a1 so that they can be printed
    addi s6, s5, -40
    beq t1, x0, endp
    lw a1, 0(s6)
    addi s5, s5, 4
    addi a0, x0, 1
    ecall # print integer ecall
    addi a1, x0, '\n'
    addi a0, x0, 11
    ecall # Print newline
    addi t1, t1, -1
    j end
    
endp:
    addi a0, x0, 10
    ecall # terminate ecall


