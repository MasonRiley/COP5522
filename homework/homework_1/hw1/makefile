CC=gcc
CFLAG= -Wall -I. -O0
OPT_CFLAG= -Wall -I. -O3

TARGETS=unoptimized opt1 opt2 opt3 optimized

all: $(TARGETS)

optimized: optimized.o microtime.o
	$(CC) -o $@ $^

opt3: opt3.o microtime.o
	$(CC) -o $@ $^

opt2: opt2.o microtime.o
	$(CC) -o $@ $^

opt1: opt1.o microtime.o
	$(CC) -o $@ $^

unoptimized: unoptimized.o microtime.o
	$(CC) -o $@ $^

optimized.o: optimized.c microtime.h
	$(CC) $(OPT_CFLAG) -c $<  

opt3.o: opt3.c microtime.h
	$(CC) $(CFLAG) -c $<

opt2.o: opt2.c microtime.h
	$(CC) $(OPT_CFLAG) -c $<  

opt1.o: opt1.c microtime.h
	$(CC) $(CFLAG) -c $<

unoptimized.o: unoptimized.c microtime.h
	$(CC) $(CFLAG) -c $<

microtime.o: microtime.c microtime.h
	$(CC) $(CFLAG) -c $<

# Add your rules here.
# Example: code in opt1.c

# opt1: opt1.o microtime.o
# 	$(CC) -o $@ $^

# opt1.o: opt1.c microtime.h
# 	$(CC) $(CFLAG) -c $<


clean:
	rm -f *.o *~ core $(TARGETS)
