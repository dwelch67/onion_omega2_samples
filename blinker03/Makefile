
GNUMIPS ?= mips-elf


ENDIAN = -EL
AOPS = $(ENDIAN) --warn --fatal-warnings 
COPSx = $(ENDIAN) -G 0 -Wall -Werror -O2 -nostdlib -nostartfiles -ffreestanding -march=24kec
COPS = $(ENDIAN) -G 0 -Wall -Werror -O2 -nostdlib -nostartfiles -ffreestanding -mips1

gcc : notmain.bin omega2.bin

clean :
	rm -f *.o
	rm -f *.bin
	rm -f *.hex
	rm -f *.elf
	rm -f *.list
	rm -f *.srec

vectors.o : vectors.s
	$(GNUMIPS)-as $(AOPS) vectors.s -o vectors.o

notmain.o : notmain.c
	$(GNUMIPS)-gcc $(COPS) -c notmain.c -o notmain.o

notmain.elf : memmap vectors.o notmain.o 
	$(GNUMIPS)-ld $(ENDIAN) vectors.o notmain.o -T memmap -o notmain.elf
	$(GNUMIPS)-objdump -D notmain.elf > notmain.list

notmain.bin : notmain.elf
	$(GNUMIPS)-objcopy --srec-forceS3 notmain.elf -O srec notmain.srec
	$(GNUMIPS)-objcopy notmain.elf -O binary notmain.bin

omega2.bin : notmain.bin
	mkimage -A mips -O linux -T standalone -C none -a 0xA0000000 -e 0xA0000000 -n "notmain" -d notmain.bin omega2.bin

