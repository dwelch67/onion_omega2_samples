
extern void PUT32 ( unsigned int, unsigned int );
extern unsigned int GET32 ( unsigned int );
extern void dummy ( unsigned int );

#define GPIO_DSET_1 (0x10000600+0x34)
#define GPIO_DCLR_1 (0x10000600+0x44)

#define TIMER_BASE 0x10000100
#define TGLB_REG    (TIMER_BASE+0x00)
#define T0CTL_REG   (TIMER_BASE+0x10)
#define T0LMT_REG   (TIMER_BASE+0x14)
#define T0_REG      (TIMER_BASE+0x18)

static void timer_rollover ( void )
{
    unsigned int ra;

    while(1)
    {
        ra=GET32(TGLB_REG);
        if(ra&0x00000001) break;
    }
    PUT32(TGLB_REG,0x00000001);
}

int notmain ( void )
{
    PUT32(T0CTL_REG,0x00200010);
    PUT32(T0LMT_REG,62500-1);
    PUT32(T0CTL_REG,0x00200090);
    while(1)
    {
        PUT32(GPIO_DSET_1,0x1000);
        timer_rollover();
        PUT32(GPIO_DCLR_1,0x1000);
        timer_rollover();
    }
    //return(0);
}
