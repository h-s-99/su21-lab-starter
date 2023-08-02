.globl main
.data
a: .word 7
b: .word 0 0 0

.text
main:
    addi s0, x0, 3 #s0 to hold the value of i
    lw s1, a       #s1 to hold the value of a
    la s2, b       #s2 to hold the address of b
    #initialize the values of temporary registers to 0
    add t3, x0, x0
    add t2, x0, x0
    add t1, x0, x0
loop:
    #for loop runs from s0(i.e 'i') = 3 till its 0 
    beq s0, x0, end
    # to store values of the first two iterations into t2 and t1
    add t2, t1, x0
    add t1, t3, x0
    # equivalent to i = i -1
    addi s0, s0, -1
    # the arithematic expression is computed
    mul s3, s0, s1
    add s4, s3, s1
    # stores value of the last iteration in t3
    add t3, s4, x0
    j loop
end:
    sw t3, 0(s2) #stores the first value in the array s2
    add a1, t3, x0
    addi a0, x0, 1
    ecall # print integer ecall
    addi a1, x0, '\n'
    addi a0, x0, 11
    ecall # Print newline
    
    sw t1, 4(s2) #stores the second value in the array s2
    add a1, t1, x0
    addi a0, x0, 1
    ecall # print integer ecall
    addi a1, x0, '\n'
    addi a0, x0, 11
    ecall # Print newline

    sw t2, 8(s2) #stores the third value in the array s2
    add a1, t2, x0
    addi a0, x0, 1
    ecall # print integer ecall
    addi a1, x0, '\n'
    addi a0, x0, 11
    ecall # Print newline
    
    addi a0, x0, 10
    ecall # terminate ecall