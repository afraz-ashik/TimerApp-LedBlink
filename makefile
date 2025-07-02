# Remove folders/files
RM = rm -f -r


# C compiler
CC = gcc

# Compiler for 64 bit ARM architecture based linux system
CC64 = aarch64-linux-gnu-gcc

# Warning flags
WFLAG = -Wall -Wextra -Werror

# Include flags
INCLUDES = -I. -IappTimer -ILedSimulation

# Flag that combines warning and include flag
CFLAGS = $(WFLAG) $(INCLUDES)

#Flag to generate object file
SRCFLAG = -c

#Flag to generate object file with debug information
DSRCFLAG = -g -c

#Flag to generate assembly file
ASMFLAG = -S

# Make directory command
MAKEDIRCMD = mkdir -p

# Directory names
DIR = release/ debug/

# Path for the generated files
EXEDIR = -o release/$(@)

#  Path for Debug support files
DEBUGDIR = -o debug/$(@)

# Path to the file appTimer.c
APPTIMER_C = appTimer/appTimer.c

# Path to the file LedSimulation.c
LEDSIMULATION_C = LedSimulation/LedSimulation.c

# Path to the file main.o
MAIN_O = release/main.o

# Path to the file appTimer.o
APPTIMER_O = release/appTimer.o

# Path to the file LedSimulation.o
LEDSIMULATION_O = release/LedSimulation.o

# Path to the file main.s
MAIN_S = release/main.s

# Path to the file appTimer.o
APPTIMER_S = release/appTimer.s

# Path to the file LedSimulation.s
LEDSIMULATION_S = release/LedSimulation.s

# Rules

# Execute all rules except clean
all:makeDir linux output rpi

# Create required directory if it doesn't exist
makeDir:
	$(MAKEDIRCMD) $(DIR)

# Call rules to create object and assembly files
# Path to find .c files
VPATH = .:appTimer/:LedSimulation/:release/

OBJ = $(MAIN_O) $(APPTIMER_O) $(LEDSIMULATION_O)

ASM = $(MAIN_S) $(APPTIMER_S) $(LEDSIMULATION_S)

linux: makeDir $(OBJ) $(ASM)

release/%.o : %.c
	$(CC) $(CFLAGS) $(SRCFLAG) $^ -o $@

debug/%.o : %.c
	$(CC) $(CFLAGS) $(DSRCFLAG) $^ -o $@

release/%.s : %.c
	$(CC) $(CFLAGS) $(SRCFLAG) $^ -o $@

# Create the output file
output: makeDir appTimerOutput.exe

appTimerOutput.exe:
	$(CC) $(MAIN_O) $(APPTIMER_O) $(LEDSIMULATION_O) $(EXEDIR)

# Cross compile
rpi: makeDir appTimerArm64

appTimerArm64:
	$(CC64) main.c $(APPTIMER_C) $(INCLUDES) $(LEDSIMULATION_C) $(EXEDIR)

# remove the Generated folders and files
clean: 
	$(RM) $(DIR)

