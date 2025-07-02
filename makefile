RM = rm -f
CC = gcc
CC64 = aarch64-linux-gnu-gcc

CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I. -IappTimer -ILedSimulation

OUTPUTS = release/$(@)
DEBUG = debug/$(@)

APPTIMER_C_PATH = appTimer/appTimer.c
LEDSIMULATION_C_PATH= LedSimulation/LedSimulation.c
APPTIMER_O_PATH = release/appTimer.o
LEDSIMULATION_O_PATH= release/LedSimulation.o

all: linux output rpi

# Create object files
linux: main.o main.s appTimer.o appTimer.s LedSimulation.o LedSimulation.s
# Create object file for main.c

main.o: main.c $(APPTIMER_C_PATH) $(LEDSIMULATION_C_PATH)
	$(CC) $(CFLAGS) -c $(CPPFLAGS) -o $(OUTPUTS) main.c
	$(CC) $(CFLAGS) -c $(CPPFLAGS) -o $(DEBUG) main.c

main.s: main.c $(APPTIMER_C_PATH) $(LEDSIMULATION_C_PATH)
	$(CC) $(CFLAGS) -S $(CPPFLAGS) -o $(OUTPUTS) main.c

# Create object file for appTimer.c
appTimer.o: $(APPTIMER_C_PATH) $(LEDSIMULATION_C_PATH)
	$(CC) $(CFLAGS) -c $(CPPFLAGS) -o $(OUTPUTS) $(APPTIMER_C_PATH)

appTimer.s: $(APPTIMER_C_PATH) $(LEDSIMULATION_C_PATH)
	$(CC) $(CFLAGS) -S $(CPPFLAGS) -o $(OUTPUTS) $(APPTIMER_C_PATH)

# Create object file for LedSimulation.c
LedSimulation.o: main.c $(APPTIMER_C_PATH) $(LEDSIMULATION_C_PATH)
	$(CC) $(CFLAGS) -c $(CPPFLAGS) -o $(OUTPUTS) $(LEDSIMULATION_C_PATH)

LedSimulation.s: main.c $(APPTIMER_C_PATH) $(LEDSIMULATION_C_PATH)
	$(CC) $(CFLAGS) -S $(CPPFLAGS) -o $(OUTPUTS) $(LEDSIMULATION_C_PATH)

output: appTimerOutput.exe

appTimerOutput.exe: release/main.o release/appTimer.o release/LedSimulation.o
	$(CC) release/main.o release/appTimer.o release/LedSimulation.o -o $(OUTPUTS)

rpi: appTimerArm64

appTimerArm64: main.c $(APPTIMER_C_PATH) $(LEDSIMULATION_C_PATH)
	$(CC64) main.c $(APPTIMER_C_PATH) $(CPPFLAGS) $(LEDSIMULATION_C_PATH) -o $(OUTPUTS)

clean: 
	$(RM) release/*.o
	$(RM) release/*.s
	$(RM) release/*.txt
	$(RM) release/*.exe
	$(RM) release/appTimerArm64