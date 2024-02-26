/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:06:12 by bapasqui          #+#    #+#             */
/*   Updated: 2024/02/26 17:44:37 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/*LIBRAIRIES*/
# include "colors.h"
# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

/*STRUCTURES*/
typedef struct s_args
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				dead;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
}					t_arg;

typedef struct s_philo
{
	int				id;
	int				is_eating;
	pthread_t		*thread_id;
}					t_philo;

/*FUNCTIONS*/
int					ft_error(int choice);
int					checker(char **arr);
int					ft_atoi(const char *str);
int					ft_atoi_check(const char *str);
int					get_args(char **arr);
int					ft_isdigit(int c);
int					check_valid_time(t_arg *args);
void				init_value(t_arg **args, char **arr);
void				print_args(t_arg *args);
int					create_thread(t_arg *args, t_philo *philo);
void				*start_dinner(t_args **args, t_philo **philo);

#endif
