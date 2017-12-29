
extern void PUT32 ( unsigned int, unsigned int );
extern unsigned int GET32 ( unsigned int );
extern unsigned int CP0_COUNT ( void );

#define GPIO_DSET_1 (0x10000600+0x34)
#define GPIO_DCLR_1 (0x10000600+0x44)

#define DELAY 575000000
#define COUNTMASK 0xFFFFFFFF

int notmain ( void )
{
    unsigned int ra;
    unsigned int rb;
    unsigned int rc;

    rc=CP0_COUNT();
    while(1)
    {
        PUT32(GPIO_DSET_1,0x1000);
        while(1)
        {
            rb=CP0_COUNT();
            ra=(rb-rc)&COUNTMASK;
            if(ra>=DELAY) break;
        }
        rc=rb;
        PUT32(GPIO_DCLR_1,0x1000);
        while(1)
        {
            rb=CP0_COUNT();
            ra=(rb-rc)&COUNTMASK;
            if(ra>=DELAY) break;
        }
        rc=rb;
    }
    //return(0);
}
