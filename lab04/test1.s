.globl main


.text
main: 
    li t2, 0xABCDE000

end:
    add a1, t2, x0
    li a0, 1
    ecall
    li a0, 10
    ecall
