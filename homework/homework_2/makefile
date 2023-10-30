CC=gcc
CFLAG= -Wall -I. -O0 -fopenmp  # Added -fopenmp

TARGETS=unoptimized optimized  # Added optimized

all: $(TARGETS)

unoptimized: unoptimized.o microtime.o
	$(CC) -o $@ $^

unoptimized.o: unoptimized.c microtime.h
	$(CC) $(CFLAG) -c $<

microtime.o: microtime.c microtime.h
	$(CC) $(CFLAG) -c $<

optimized: optimized.o microtime.o   # Rule for optimized
	$(CC) $(CFLAG) -o $@ $^

optimized.o: optimized.c microtime.h  # Compilation for optimized.c
	$(CC) $(CFLAG) -c $<

clean:
	rm -f *.o *~ core $(TARGETS)
