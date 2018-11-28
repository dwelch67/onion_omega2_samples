
//-------------------------------------------------------------------------
//-------------------------------------------------------------------------

extern void PUT32 ( unsigned int, unsigned int );
extern unsigned int GET32 ( unsigned int );
extern void dummy ( unsigned int );

#define UART0_RBR (*((volatile unsigned int *)(0x10000C00+0x00)))
#define UART0_THR (*((volatile unsigned int *)(0x10000C00+0x00)))
#define UART0_LSR (*((volatile unsigned int *)(0x10000C00+0x14)))

#define GPIO_DSET_1 (*((volatile unsigned int *)(0x10000600+0x34)))
#define GPIO_DCLR_1 (*((volatile unsigned int *)(0x10000600+0x44)))

//-------------------------------------------------------------------------
int notmain ( void )
{
    unsigned int ra;

    for(ra=0x30;;ra++)
    {
        ra&=0x37;
        UART0_THR=ra;
        while(1)
        {
            if(UART0_LSR&0x20) break;
        }
    }
    return(0);
}
//-------------------------------------------------------------------------
//-------------------------------------------------------------------------
