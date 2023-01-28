#cross compiler
CC=arm-none-eabi-gcc

#processor 
MACH =cortex-m7

#compiler flags
CFLAGS= -c -mcpu= $(MACH) -mthumb 

main.o : main.c
	$(CC) $(CFLAGS) -o main.o main.c
	
