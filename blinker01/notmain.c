
extern void PUT32 ( unsigned int, unsigned int );
extern unsigned int GET32 ( unsigned int );
extern void dummy ( unsigned int );

#define GPIO_DSET_1 (0x10000600+0x34)
#define GPIO_DCLR_1 (0x10000600+0x44)

int notmain ( void )
{
    unsigned int ra;
    while(1)
    {
        PUT32(GPIO_DSET_1,0x1000);
        for(ra=0;ra<400000;ra++) dummy(ra);
        PUT32(GPIO_DCLR_1,0x1000);
        for(ra=0;ra<400000;ra++) dummy(ra);

    }
    return(0);
}
