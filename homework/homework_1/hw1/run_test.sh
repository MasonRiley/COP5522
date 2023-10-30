# !/bin/bash

NUM_ROWS=10060 # Prime number to demonstrate superoptimized's ability to handle unaligned data
NUM_COLS=10060

echo "Unoptimized Test"
./unoptimized $NUM_ROWS $NUM_COLS
echo "-------------"

echo "Opt1 Test - Cache-awareness"
./opt1 $NUM_ROWS $NUM_COLS
echo "-------------"

echo "Opt2 Test - Cache-awareness & Compiler Flags"
./opt2 $NUM_ROWS $NUM_COLS
echo "-------------"

echo "Opt3 Test - Intel Intrinsics"
./opt3 $NUM_ROWS $NUM_COLS
echo "-------------"

echo "Optimized Test - Intel Intrinsics & Compiler Flags"
./optimized $NUM_ROWS $NUM_COLS
echo "-------------"
