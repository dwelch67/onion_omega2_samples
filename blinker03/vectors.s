
.globl _start
_start:

    li $sp,0xA1000000
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

.globl CP0_COUNT
CP0_COUNT:
    .word 0x40024800 #    mfc0    $2,c0_count
    jr $ra
    nop

