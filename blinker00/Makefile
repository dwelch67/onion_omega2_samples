
GNUMIPS ?= mips-elf


ENDIAN = -EL
AOPS = $(ENDIAN) --warn --fatal-warnings 
COPS = $(ENDIAN) -Wall -Werror -O2 -nostdlib -nostartfiles -ffreestanding -march=24kec

gcc : blinker00.bin omega2.bin

clean :
	rm -f *.o
	rm -f *.bin
	rm -f *.hex
	rm -f *.elf
	rm -f *.list
	rm -f *.bin.lzma

vectors.o : vectors.s
	$(GNUMIPS)-as $(AOPS) vectors.s -o vectors.o

blinker00.elf : memmap vectors.o
	$(GNUMIPS)-ld $(ENDIAN) vectors.o -T memmap -o blinker00.elf
	$(GNUMIPS)-objdump -D blinker00.elf > blinker00.list

blinker00.bin : blinker00.elf
	$(GNUMIPS)-objcopy blinker00.elf -O binary blinker00.bin

omega2.bin : blinker00.bin
	mkimage -A mips -O linux -T standalone -C none -a 0x00000000 -e 0x00000000 -n "blinker00" -d blinker00.bin omega2.bin

