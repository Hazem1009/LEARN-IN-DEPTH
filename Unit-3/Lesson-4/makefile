CC = arm-none-eabi-
CFLAGS = -mcpu=cortex-m4 -g -gdwarf-2
INCS = -I .
LIBS = 
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
As = $(wildcard *.s)
AsOBJ= $(As:.s=.o)
Project_name = TivaC_toggle_Led

all: $(Project_name).bin
	@echo "---------------Successfuly Built $(Project_name)---------------"

%.o:%.c
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) $< -o $@



$(Project_name).elf: $(OBJ)
	$(CC)ld.exe -T linkerscript.ld $(LIBS) $(OBJ) $(AsOBJ) -o $@ -Map="mapfile.map"
	cp $(Project_name).elf $(Project_name).axf


$(Project_name).bin : $(Project_name).elf
	$(CC)objcopy.exe -O binary $< $@

clean:
	rm *.elf *.o *.map *.axf *.bin 