
.globl _start
_start:
    lui $2,0x1000
    li  $3,0x1000
    sw  $3,0x634($2)
    b .
    nop
