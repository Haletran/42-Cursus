/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:06:12 by bapasqui          #+#    #+#             */
/*   Updated: 2024/02/22 18:10:52 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/*COLORS*/
# define BLACK "\033[30m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"
# define RESET "\033[0m"

/*LIBRAIRIES*/
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
	pthread_t		thread_id;
	struct s_philo *next;
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
int create_thread(t_arg *args, t_philo *philo);

#endif // !PHILO_H
