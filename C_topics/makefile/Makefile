#******************************************************************************

#*****************************************************************************

#cross compiler
CC=arm-none-eabi-gcc

#processor 
CPU = -mcpu=cortex-m7

#compiler flags
CFLAGS= -c $(CPU) -mthumb 

BUILD_DIR = build

all : main.o $(BUILD_DIR)

main.o : main.c
	$(CC) $(CFLAGS) -o main.o main.c

$(BUILD_DIR):
	mkdir $@


# Cleaning recipe
clean:
	-rm -fR $(BUILD_DIR):
	
