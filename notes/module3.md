# Open-MP Based Programming

## Speedup

S = T_serial / T_parallel

T_parallel = T_serial / p

S = speedup
T_parallel = Parallel run-time
T_serial = Serial run-time
p = number of cores

## Efficiency

E = S / p

E = T_serial / (p * T_parallel)

## Effect of Overhead

T_parallel = T_serial / p + T_overhead

## Scalability

* In general, a problem is scalable if it can handle ever increasing problem sizes

* If we increase the number of processes/threads and keep the efficiency fixed without increasing problem size, the problem is strongly scalable

* If we keep the efficiency fixed by increasing the problem size at the same rate as we increase number of processes/threads, the problem is weakly scalable