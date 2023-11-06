# Homework 2

## Data

All relevant data can be found in hw2.xlsx or here:

https://docs.google.com/spreadsheets/d/11vxwa0WOuJryH6M0RlsLizdxCJHXp1COny9GY0wUPNc/edit?usp=sharing

## Versions

| Version Name | Description                                              |
| ------------ | -------------------------------------------------------- |
| unoptimized  | original code                                            |
| opt1         | #pragma omp parallel num_threads(n)                      |
| opt2         | #pragma omp parallel for num_threads(8) private(k)       |
| opt3         | #pragma omp parallel for schedule(dynamic, 8) private(k) |
| optimized    | #pragma omp parallel for private(k)                      |