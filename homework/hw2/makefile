CC=gcc
CFLAGS= -Wall -I. -O0 -fopenmp

TARGETS=unoptimized # add your target here

all: $(TARGETS)

unoptimized: unoptimized.o microtime.o
	$(CC) -fopenmp -o $@ $^

unoptimized.o: unoptimized.c microtime.h
	$(CC) $(CFLAGS) -c $<

microtime.o: microtime.c microtime.h
	$(CC) $(CFLAGS) -c $<

# Add your rules here.
# Example: code in opt1.c

# opt1: opt1.o microtime.o
# 	$(CC) -fopenmp -o $@ $^

# opt1.o: opt1.c microtime.h
# 	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o *~ core $(TARGETS)
