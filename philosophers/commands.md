## Threads

1. `pthread_create`: Creates a new thread.
2. `pthread_join`: Waits for a specific thread to finish execution.
3. `pthread_detach`: Marks a thread as detached so that its resources are automatically released when it exits.

## Mutex

1. `pthread_mutex_init`: Initializes a mutex.
2. `pthread_mutex_destroy`: Destroys a mutex.
3. `pthread_mutex_lock`: Locks a mutex.
4. `pthread_mutex_unlock`: Unlocks a mutex.

## Others

1. `memset`
2. `gettimeofday`
3. `malloc` `free` `write`
4. `usleep`


## Routine 

- Le philo doit penser / manger / dormir
jusqu'a que ce que tous le monde ait mange 
ou que un philo meurt.
- prendre en compte le dernier parametre si 
il existe
- autant de fourchettes que de philos
