#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material.
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Makefile for the project with multiple platform support - x86 and arm
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <file>.i - generates the corresponding pre-processed file
#      <file>.asm - generates the corresponding assembly file
#      <file>.o - generates the corresponding object file
#      <file>.d - generates the corresponding dependency file
#      compile-all - compiles all c files in ./src directory
#      build  - compiles and links to produce executable  in current directory.
#								Also, the corresponding map and assembly is generated.
#      clean - cleans all generated files such as .o, .i, .d, .asm,
# 						 .map, .out in current directory
#
# Platform Overrides:
#      PLATFORM - HOST/MSP432 - build the project for input architecture
#
#------------------------------------------------------------------------------

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
	
