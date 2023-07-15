CC = arm-none-eabi-
CFLAGS = -mcpu=cortex-m3 -gdwarf-2
INCS= -I . 
LIBS= 
SRC=$(wildcard *.c) #Text Replacement
OBJ=$(SRC:.c=.o) 	#Text Replacement

AS=$(wildcard *.s) #Text Replacement
AsOBJ = $(AS:.s=.o) #Text Replacement


all: learn-in-depth.bin

%.o : %.s
	$(CC)as.exe $(CFLAGS) $< -o $@

%.o: %.c
	$(CC)gcc.exe $(CFLAGS) -c  $(INCS) $< -o $@	

learn-in-depth.elf : startup.o $(OBJ)
	$(CC)ld.exe  -T linkerscript.ld $(LIBS) -Map="mapfile.map" startup.o $(OBJ) -o $@

learn-in-depth.bin : learn-in-depth.elf
	$(CC)objcopy.exe -O binary $< $@
	@echo "--------------BUILD IS DONE!!--------------"


clean : 
	rm *.o *.elf *.map *.bin 
	@echo "--------------Cleaned Compiled,linked and elf files from directory--------------------"


