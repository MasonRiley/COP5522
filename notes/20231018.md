#

Three different extensions to C

1. Message-Passing Interface (MPI)
2. Posix Threads (Pthreads)
3. 

# Type of Parallel Systems

* Shared Memory
    * The cores can share access to computer's memory
    * Coordinate the cores by having them examine and update shared memory locations
* Distributed Memory
    Each core has its own, private memory
    The cores must communicate explicitly by sending messages across a network

# Terminology

* Concurrent computing - A program is one in which multiple tasks can be in progress at any instant

* Parallel computing - a program is one in which multiple tasks cooperate closely to solve a problem

* Distributed computing - a program may need to cooperate with other programs to solve a problem

# Parallel Programming Models

* Shared Memory
    * OpenMP
    * Pthreads
* Message passing (distributed memory)
    * MPI
* Data parallel
    * OpenCL (FYI)
    * CUDA (FYI)
* Task Parallel
    * OpenMP
* Hybrid
    * MPI + OpenMP
    * MPI + Pthreads