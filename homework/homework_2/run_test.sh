# !/bin/bash

make clean

make

NUM_ROWS=1000 # Prime number (when starting at 0)
NUM_COLS=1000

echo ""
echo ======== 1000 ==========
echo ""
echo "Unoptimized Test"
./unoptimized $NUM_ROWS $NUM_COLS
echo "-------------"

echo "Opt1 Test"
./opt1 $NUM_ROWS $NUM_COLS
echo "-------------"

echo "Opt2 Test"
./opt2 $NUM_ROWS $NUM_COLS
echo "-------------"

echo "Opt3 Test"
./opt3 $NUM_ROWS $NUM_COLS
echo "-------------"

echo "Optimized Test"
./optimized $NUM_ROWS $NUM_COLS
echo "-------------"

echo ""
echo ======== 5000 ==========
echo ""

NUM_ROWS=5000 # Prime number (when starting at 0)
NUM_COLS=5000

echo "Unoptimized Test"
./unoptimized $NUM_ROWS $NUM_COLS
echo "-------------"

echo "Opt1 Test"
./opt1 $NUM_ROWS $NUM_COLS
echo "-------------"

echo "Opt2 Test"
./opt2 $NUM_ROWS $NUM_COLS
echo "-------------"

echo "Opt3 Test"
./opt3 $NUM_ROWS $NUM_COLS
echo "-------------"

echo "Optimized Test"
./optimized $NUM_ROWS $NUM_COLS
echo "-------------"

echo ""
echo ======== 10000 ==========
echo ""

NUM_ROWS=10000 # Prime number (when starting at 0)
NUM_COLS=10000

echo "Unoptimized Test"
./unoptimized $NUM_ROWS $NUM_COLS
echo "-------------"

echo "Opt1 Test"
./opt1 $NUM_ROWS $NUM_COLS
echo "-------------"

echo "Opt2 Test"
./opt2 $NUM_ROWS $NUM_COLS
echo "-------------"

echo "Opt3 Test"
./opt3 $NUM_ROWS $NUM_COLS
echo "-------------"

echo "Optimized Test"
./optimized $NUM_ROWS $NUM_COLS
echo "-------------"
