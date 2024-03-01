/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:36:53 by bapasqui          #+#    #+#             */
/*   Updated: 2024/03/01 15:02:24 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <pthread.h>
# include <stdbool.h>

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

#endif