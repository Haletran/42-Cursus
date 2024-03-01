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


## Le projet

- Le philo doit penser / manger / dormir
jusqu'a que ce que tous le monde ait mange 
ou que un philo meurt.
- prendre en compte le dernier parametre si 
il existe
- autant de fourchettes que de philos
- quand un philo a ces deux fourchettes ils mangent obligatoirement 
et les philos n - 1 && n + 1ne peuvent pas manger car pas de
fourchettes
- ajouter des conditions pour le temp de mort et le nb de repas a satisfaire
- mieux gere les fourchettes ainsi que quelle philo est en train de faire quelque chose
- gere le temps en ms
- gere quelle philo a le droit de manger en premier
- si le dernier param est present le prendre en compte
- avoir un meilleur print des valeurs de depart
- comprendre mieux les threads (create, join)
- l'ordre des philos doit etre defini pour qu'aucun philo ne meure
- Il ne faut pas qu'ils prennent leurs fouchettes en meme temps sinon deadlock


## Les prints 

Any state change of a philosopher must be formatted as follows:
◦ timestamp_in_ms X has taken a fork
◦ timestamp_in_ms X is eating
◦ timestamp_in_ms X is sleeping
◦ timestamp_in_ms X is thinking
◦ timestamp_in_ms X died

## Avoir un projet propre

- Setup les structures (philos, forks, variables)
- Setup les threads
- Setup les mutexs (sur tous)
- Setup les variables
- Structure du projet clean ✔️



## LINKS 

- https://medium.com/swlh/the-dining-philosophers-problem-bbdb92e6b788
- 