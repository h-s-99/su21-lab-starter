.globl main

.data
arr: .word 0,0,0,0,0,0,0,0,0,0
num: .word 7


.text
main:
    addi s0, x0, 10
    la t0, num
    lw a0, 0(t0)
    la s5, arr
    addi t1, x0, 10
    j dataArray
    
dataArray:
    beq s0, x0, end
    addi s0, s0, -1
    jal ra, subt
    sw a0, 0(s5)
    addi t6, x0, 4
    add s5, t6, s5
    lw a0, 0(sp)
    addi sp, sp, 4
    j dataArray
    
compare:
    addi sp, sp, -4
    sw a0, 0(sp)
    blt t5, x0, next
    addi a0, x0, 1
    jr ra
    
next:
    add a0, x0, x0
    jr ra
    
subt:
    add t3, x0, a0
    add t4, x0, s0
    sub t5, t3, t4
    j compare
    
end:
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


