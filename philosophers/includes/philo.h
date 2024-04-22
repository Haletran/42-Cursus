/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:01:13 by bapasqui          #+#    #+#             */
/*   Updated: 2024/04/22 11:20:06 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define RESET "\033[0m"

# define SUCCESS 0
# define FAILURE 1

typedef enum e_status
{
	EATING,
	SLEEPING,
	THINKING,
	DEAD
}						t_status;

typedef struct s_philo
{
	int					id;
	int					time;
	int					eat_count;
	int					last;
	t_status			status;
	int					is_full;
	pthread_mutex_t		*fork;
	pthread_t			philos;
	struct s_infos		*infos;
	struct s_philo		*next;
	struct s_philo		*prev;
}						t_philo;

typedef struct s_monitor
{
	int					nb_meals;
	pthread_t			monitor;
	pthread_mutex_t		*forks_mutex;
	pthread_mutex_t		print_mutex;
	pthread_mutex_t		*monitor_mutex;
}						t_monitor;

typedef struct s_infos
{
	int					nb_philo;
	int					t_die;
	int					t_eat;
	int					t_sleep;
	int					n_eat;
	int					nb_meals;
	volatile int		end_of_simulation;
}						t_infos;

typedef struct s_table
{
	struct s_infos		*infos;
	struct s_philo		*philo;
	struct s_monitor	*server;
}						t_table;

/*EXEC*/
void					*init_table(char **argv, t_table *table);
t_philo					*init_stack(t_philo *a, int nb_philo, t_table *table);
int						parse_input(char **argv);
int						setup_philo(t_table *table);
void					*routine(void *params);
void					ft_join(t_philo *philo);
void					print_status(t_philo *philos);

/*LIB*/
int						ft_isdigit(int c);
int						ft_atoi(const char *str);
void					print_tab(char **tab);
int						print_error(char *str);
void					*ft_calloc(size_t elementCount, size_t elementSize);
void					ft_free(t_table **table);
void					print_lst(t_philo *philo);

/*LST*/
void					*ft_lst_new(int content, t_table *table);
t_philo					*ft_lstadd_back(t_philo *lst, int value,
							t_table *table);

/*ACTIONS*/
void					is_thinking(t_philo *philo);
void					is_eating(t_philo *philo);
void					is_sleeping(t_philo *philo);

#endif