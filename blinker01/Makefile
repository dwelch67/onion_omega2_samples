
GNUMIPS ?= mips-elf


ENDIAN = -EL
AOPS = $(ENDIAN) --warn --fatal-warnings 
COPS = $(ENDIAN) -Wall -Werror -O2 -nostdlib -nostartfiles -ffreestanding -march=24kec

gcc : blinker01.bin omega2.bin

clean :
	rm -f *.o
	rm -f *.bin
	rm -f *.hex
	rm -f *.elf
	rm -f *.list
	rm -f *.srec

vectors.o : vectors.s
	$(GNUMIPS)-as $(AOPS) vectors.s -o vectors.o

blinker01.o : blinker01.c
	$(GNUMIPS)-gcc $(COPS) -c blinker01.c -o blinker01.o

blinker01.elf : memmap vectors.o blinker01.o 
	$(GNUMIPS)-ld $(ENDIAN) vectors.o blinker01.o -T memmap -o blinker01.elf
	$(GNUMIPS)-objdump -D blinker01.elf > blinker01.list

blinker01.bin : blinker01.elf
	$(GNUMIPS)-objcopy --srec-forceS3 blinker01.elf -O srec blinker01.srec
	$(GNUMIPS)-objcopy blinker01.elf -O binary blinker01.bin

omega2.bin : blinker01.bin
	mkimage -A mips -O linux -T standalone -C none -a 0x00000000 -e 0x00000000 -n "blinker01" -d blinker01.bin omega2.bin

