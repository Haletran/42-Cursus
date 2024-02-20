/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:06:12 by bapasqui          #+#    #+#             */
/*   Updated: 2024/02/20 17:00:23 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/*LIBRAIRIES*/
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>
# include <limits.h>

/*STRUCTURES*/
typedef struct s_args
{
	int	nb_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	must_eat;
}		t_arg;

typedef	struct s_philo
{
	pthread_t philo_id;
	struct s_philo *next;
} t_philo;



/*FUNCTIONS*/
int		ft_error(int choice);
int		checker(char **arr);
int		ft_atoi(const char *str);
t_arg	init_value(t_arg *args, char **arr);
int	ft_atoi_check(const char *str);
int	get_args(char **arr);
int	ft_isdigit(int c);

#endif // !PHILO_H
