
.globl _start
_start:

    li $sp,0x84000000
    nop

    jal notmain
    nop
    nop
    b .
    b notmain
    nop
    nop

    lui $2,0x1000
    li  $3,0x1000
    sw  $3,0x634($2)

    lui $2,0x1000
    li  $3,0x55
    sw  $3,0xC00($2)

    b .
    nop
    nop
    j .
    nop
    nop
    nop


    lui $2,0
    nop
    jr $31
    nop

    lui $2,0x1000
    li  $3,0x1000
    sw  $3,0x634($2)
    b .
    nop

