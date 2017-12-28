
.globl _start
_start:

    li $sp,0x81000000
    jal notmain
    nop
    b .
    nop

.globl PUT32
PUT32:
    sw $a1,0($a0)
    jr $ra
    nop

.globl GET32
GET32:
    lw $v0,0($a0)
    jr $ra
    nop

.globl dummy
dummy:
    jr $ra
    nop


