/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:06:12 by bapasqui          #+#    #+#             */
/*   Updated: 2024/02/27 17:09:56 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/*LIBRAIRIES*/
# include "colors.h"
# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

/*STRUCTURES*/
typedef pthread_mutex_t	t_mtx;
typedef struct s_table	t_table;

typedef struct s_fork
{
	t_mtx				fork;
	int					fork_id;
}						t_fork;

typedef struct s_philo
{
	int					*id;
	long				meals_counter;
	long				last_meal_time;
	t_fork				*right_fork;
	t_fork				*left_fork;
	pthread_t			*thread_id;
	t_table				*table;
}						t_philo;

struct					s_table
{
	int					nb_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					must_eat;
	int					start_simulation;
	bool				end_simulation;
	t_fork				*forks;
	t_philo				*philos;
};

/*FUNCTIONS*/
int						ft_error(int choice);
int						checker(char **arr);
int						ft_atoi(const char *str);
int						ft_atoi_check(const char *str);
int						get_args(char **arr);
int						ft_isdigit(int c);
void					create_thread(t_table **table);
int						check_valid_time(t_table *table);
void					init_value(t_table **table, char **arr);
void					print_table(t_table *table);
void					*start_dinner(t_table **table);
void					ft_free_all(t_table **table);
void	*runtime(void *param);


#endif
