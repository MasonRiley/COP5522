CC=gcc
CFLAG= -Wall -I. -fopenmp  # Added -fopenmp

TARGETS=unoptimized optimized opt1 opt2 opt3 # Added optimized

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

opt1: opt1.o microtime.o
	$(CC) $(CFLAG) -o $@ $^

opt1.o: opt1.c microtime.h
	$(CC) $(CFLAG) -c $<

opt2: opt2.o microtime.o
	$(CC) $(CFLAG) -o $@ $^

opt2.o: opt2.c microtime.h
	$(CC) $(CFLAG) -c $<

opt3: opt3.o microtime.o
	$(CC) $(CFLAG) -o $@ $^

opt3.o: opt3.c microtime.h
	$(CC) $(CFLAG) -c $<

clean:
	rm -f *.o *~ core $(TARGETS)
