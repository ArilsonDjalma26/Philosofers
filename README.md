*This project was created as part of the 42 curriculum by aalbano.*

# Description
**Philosophers** is a simulation of the classic *Dining Philosophers* concurrency problem, whose goal is to study and apply fundamental concepts of **concurrent programming**, such as threads, mutexes, synchronization, and time management.

The program simulates philosophers sitting at a table who alternate between thinking, eating, and sleeping.  
To eat, each philosopher needs two forks, which are shared resources. The main challenge of the project is to ensure that these resources are used safely and synchronously, avoiding problems such as **race conditions**, **deadlocks**, and **undefined behavior**.

In addition to functioning correctly, the project requires a robust, predictable, and secure implementation, strictly adhering to concurrency rules.

---

# Project Objectives
- Understand how **threads** work in C
- Ensure **correct synchronization** between multiple threads
- Avoid deadlocks, race conditions, and starvation
- Implement precise lifetime control
- Ensure resource cleanup and correct program termination

---

# Instructions

## Compilation
Compile the project using the provided Makefile:
```bash
make
```

## Execution

Run the program passing the required arguments:

./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]

Example:
./philo 5 800 200 200

With minimum number of meals:

./philo 5 800 200 200 7

## Arguments

| Argument | Description |
|----------|-------------|
| `number_of_philosophers` | Number of philosophers (and forks) |
| `time_to_die` | Maximum time (ms) without eating before dying |
| `time_to_eat` | Time (ms) spent eating |
| `time_to_sleep` | Time (ms) spent sleeping |
| `number_of_times_each_philosopher_must_eat` | *(optional)* Minimum number of meals per philosopher |

## Resources

### Documentation & References
- POSIX Threads (pthread) - man7.org
- pthread_create - Thread creation
- pthread_mutex_lock - Mutex operations
- gettimeofday - Time measurement

### Articles & Tutorials
- Dining Philosophers Problem - Wikipedia
- Deadlock - Wikipedia
- Race Condition - Wikipedia

---

### Use of AI in the Project

AI was used exclusively as theoretical support, respecting the rules of 42.

It was used for:

-Clarification of concepts (threads, mutex, deadlock, race condition);
-Theoretical review of logic before implementation;
-Identification of possible synchronization problems;
-Suggestions for organization and modularization;
-Support in checking for memory leaks and best practices;

The entire implementation was done manually by the author.
