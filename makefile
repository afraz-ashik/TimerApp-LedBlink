# List if directories for make to search
VPATH = .:appTimer/:LedSimulation/:release/

# Remove folders/files
RM = rm -f -r

# C compiler
CC = gcc

# Compiler for 64 bit ARM architecture based linux system
CCRPI = aarch64-linux-gnu-gcc

# Flag that combines warning and include flag
CFLAGS = -Wall -Wextra -Werror -I. -IappTimer -ILedSimulation

#Flag to generate object file
SRCFLAG = -c

#Flag to generate object file with debug information
DSRCFLAG = -g -c -O0

#Flag to generate assembly file
ASMFLAG = -S

# Make directory command
MAKEDIRCMD = mkdir -p

# Directory names
DIR = release/ debug/

# Path for the generated files
EXEDIR = -o release/$(@)

# All .c files
CFILE = $(wildcard *.c appTimer/*.c LedSimulation/*.c)

# Path for .o files
OBJ = release/main.o release/appTimer.o release/LedSimulation.o

# Path for .s files
ASM = $(patsubst release/%.o,%.c,$(OBJ))

# Path for debug supported .o files
OBJDEB = $(subst release,debug,$(OBJ))

# Rules

# Execute all rules except clean
all:makeDir linux rpi

# Create required directory if it doesn't exist
makeDir:
	$(MAKEDIRCMD) $(DIR)

# Call rules to create object and assembly files
linux: makeDir $(OBJ) $(ASM) $(OBJDEB) output

# Using pattern matching to compile

# Object file
release/%.o : %.c
	$(CC) $(CFLAGS) $(SRCFLAG) $^ -o $@

# Debug supported object file
debug/%.o : %.c
	$(CC) $(CFLAGS) $(DSRCFLAG) $^ -o $@

# Assembly files
release/%.s : %.c
	$(CC) $(CFLAGS) $(ASMFLAG) $^ -o $@

# Create the output file
output: appTimerOutput.exe

appTimerOutput.exe:
	$(CC) $(OBJ) $(EXEDIR)

# Cross compile for Raspberrypi
rpi: makeDir appTimerArm64

appTimerArm64:
	$(CCRPI) $(CFILE) $(CFLAGS) $(EXEDIR)


# remove the Generated folders and files
clean: 
	$(RM) $(DIR)
