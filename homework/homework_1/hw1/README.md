# Homework 1

## Usage

To easily test, `run_test.sh` runs all versions of the code similar to `./unoptimized 10060 10060`. I chose this number since its prime (10061 when not starting at 0) and demonstrates the code's ability to handle matrices not divisible by 4.

```bash
make
./run_test.sh
```

## Versions

| Version Name | Description                       |
| ------------ | --------------------------------- |
| unoptimized  | original code                     |
| opt1         | cache-aware                       |
| opt2         | cache-aware & gcc flags           |
| opt 3        | Intel SIMD Intrinsics             |
| optimized    | Intel SIMD Intrinsics & gcc flags |