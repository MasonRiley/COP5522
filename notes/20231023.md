# Parallel Hardware and Parallel Software

## Central Processing Unit (CPU)

Divided into two parts:

1. Control Unit - responsible for deciding which instruction in a program should be executed (the boss).
2. Arithmetic and Logic Unit - Responsible for executing instructions

## Key Terms

1. Register - very fast storage, part of the CPU
1. Program Counter - stores address of the next instruction to be executed
1. Bus - wires and hardware that connects the CPU and memory

## An operating system "process"

* An instance oif a computer program that is being executed
* Components of a process:
    * The executable machine language program
    * A block of memory
    * Descriptors of resources that OS has allocated to the process
    * Security information
    * Information about the state of the process

## Multitasking

* Gives the illusion that a single processor system is running multiple programs simultaneously
* Each process takes turns running
* After time is up

## Threading

* Threads are contained within processes
* They allow programmers to divide their programs into independent tasks
* The hope is that when one thread blocks because it is waiting on a resource, another will have work to do and can run

> Starting a thread is called forking, terminating a thread is called joining

## Basics of caching

* A collection of memory locations that can be accessed in less time than some other memory locations

* A CPU cache is typically located on the same chip, or one that can be accessed much faster than ordinary memory

> Between register and memory in speed

## Principle of Locality

* Accessing one location is followed by an access of a nearby location

* Spatial Locality - accessing a nearby location

* Temporal Locality - accessing in the near future

## Issues with Cache

* When a CPU writes data to cache, the value in cache may be inconsistent with the value in main memory

* Write-through caches handle this by updating the data in main memory at the time it is written to cache

* Write-back (faster) caches mark data in the cache as dirty. When the cache line is replaced by a new cache line from memory, the dirty line is written to memory.

## Cache Mappings

* Full associative - a new line can be placed at any location in the cache (Temporal locality)

* Direct Mapped - each cache line has a unoque location in the cache to which it will be assigned (Spatial locality)

* n-way set associative - each cache line can be placed in one of n different locations in the cache

## Virtual Memory

* If we run a very large program or a program that accesses vary large data sets, all of the instructions and data may not fit into main memory

* Virtual memory functions as a cache for secondary storage

## Translation-lookaside Buffer (TLB)

* Using a page table has the potential to significantly increase each program's overall run-time

* A special address translation cache in the processor

## Instruction Level Parallelism (ILP)

* Attempts to improve processor performance by having multiple processor components or functional units simultaneously execution instructions

* Pipelining - functional units are arranged in stages

* Multiple Issue - 



## Side notes

Compilers

1. make (unsafe)
1. cmake (safer make)
1. ninja

