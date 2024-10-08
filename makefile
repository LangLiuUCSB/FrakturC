CC = clang # Define the compiler

CFLAGS = -Wall -Wextra -pedantic # Define the compiler flags

TARGET = main # Define the target executable

TIMER_TARGET = performance_timer

SRCS = main.c utils.c MAST.c _num.c Nnum.c Znum.c Qnum.c Rnum.c Cnum.c # Define the source files

OBJS = $(SRCS:.c=.o) # Define the object files

all: $(TARGET) $(TIMER_TARGET) # Default rule to build the executable

$(TARGET): $(OBJS) # Rule to build the executable
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

$(TIMING_TARGET): timing_wrapper.o
	$(CC) $(CFLAGS) -o $(TIMING_TARGET) timing_wrapper.o

%.o: %.c # Rule to build the object files
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET) # Rule to run the executable
	./main

timer: $(TARGET) $(TIMER_TARGET) # Rule to run the executable and time performance
	./performance_timer ./main

leaks: $(TARGET) # Rule to run the executable and check for memory leaks
	leaks --atExit -- ./main

clean: # Rule to clean up the build
	rm -f $(OBJS) $(TARGET) $(TIMER_TARGET)

.PHONY: all clean run # Phony targets