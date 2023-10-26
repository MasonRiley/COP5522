CC=gcc
CFLAG= -Wall -I. -O0
#OPT_CFLAG= -Wall -I. -O3

TARGETS=unoptimized optimized superoptimized

all: $(TARGETS)

superoptimized: superoptimized.o microtime.o
	$(CC) -o $@ $^

optimized: optimized.o microtime.o
	$(CC) -o $@ $^

unoptimized: unoptimized.o microtime.o
	$(CC) -o $@ $^

superoptimized.o: superoptimized.c microtime.h
	$(CC) $(OPT_CFLAG) $(CFLAG) -c $<

optimized.o: optimized.c microtime.h
	$(CC) $(OPT_CFLAG) $(CFLAG) -c $<

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
