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

## Les prints 

Any state change of a philosopher must be formatted as follows:
◦ timestamp_in_ms X has taken a fork
◦ timestamp_in_ms X is eating
◦ timestamp_in_ms X is sleeping
◦ timestamp_in_ms X is thinking
◦ timestamp_in_ms X died

## TEST

- ./philo 2 250 140 100 passe pas
- ./philo 1 200 200 200	philo 1 ne prend qu'une fourchette et meurt au bout de 200 ms
- ./philo 2 800 200 200	personne ne meurt
- ./philo 5 800 200 200	personne ne meurt
- ./philo 5 800 200 200 7 la simulation s'arrete quand chaque philo a mange 7 fois
- ./philo 4 410 200 200	personne ne meurt
- ./philo 4 310 200 200	un philo meurt
- ./philo 4 500 200 1.2	argument invalide
- ./philo 4 0 200 200	argument invalide
- ./philo 4 -500 200 200	argument invalide
- ./philo 4 500 200 2147483647	un philo meurt au bout de 500 ms
- ./philo 4 2147483647 200 200	personne ne meurt
- ./philo 4 214748364732 200 200	argument invalide
- ./philo 4 200 210 200	un philo meurt, il faut afficher la mort avant 210 ms
- valgrind --tool=helgrind ou valgrind --tool=drd
-  ./philo 20 400 199 199 mort trop lente