#prepared by Eng Arafa
 
CC=arm-none-eabi-
CFLAGS= -gdwarf-2 -mcpu=cortex-m3 -mthumb
INCS=-I .
LIBS=
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
AS=$(wildcard *.s)
ASOBJ=$(AS:.s=.o)
Project_name = unit3_lesson5


$(Project_name).bin: $(Project_name).elf
		$(CC)objcopy.exe -O binary $< $@
		@echo "============Build is Done==========="

%.o: %.s
		$(CC)as.exe $(CFLAGS) $< -o $@

%.o: %.c
		$(CC)gcc.exe -c $(INCS) $(CFLAGS) $< -o $@  

$(Project_name).elf: $(OBJ) $(ASOBJ)
		$(CC)ld.exe -T  -nostartfiles linker_script.ld $(LIBS) $(OBJ) $(ASOBJ) -o $@ -Map=Map_File.map

clean:
	rm *.elf *.bin	
	
clean_all:
	rm *.o *.elf *.bin
	@echo "=======done cleaning==========="