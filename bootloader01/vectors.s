
.globl _start
_start:

    li $sp,0x02000000
    jal notmain
    nop
    b .
    nop

.globl PUT8
PUT8:
    sb $a1,0($a0)
    jr $ra
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

.globl BRANCHTO
BRANCHTO:
    jr $a0
    nop



