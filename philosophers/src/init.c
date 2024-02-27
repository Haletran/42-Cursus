/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:00:02 by bapasqui          #+#    #+#             */
/*   Updated: 2024/02/27 19:13:51 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec);
}

void	init_value(t_table **table, char **arr)
{
	int	i;

	i = 0;
	(*table)->nb_philo = ft_atoi(arr[1]);
	(*table)->philos = malloc(sizeof(t_table));
	(*table)->time_to_die = ft_atoi(arr[2]);
	(*table)->time_to_eat = ft_atoi(arr[3]);
	(*table)->time_to_sleep = ft_atoi(arr[4]);
	(*table)->start_simulation = get_time();
	if (arr[5])
		(*table)->must_eat = ft_atoi(arr[5]);
	(*table)->philos->id = malloc(sizeof(t_table) * (*table)->nb_philo + 1);
	(*table)->philos->right_fork = malloc(100);
	(*table)->philos->left_fork = malloc(100);
	(*table)->philos->meals_counter = 0;
}

int	check_valid_time(t_table *table)
{
	if (table->time_to_die < 60)
		return (0);
	else if (table->time_to_eat < 60)
		return (0);
	else if (table->time_to_sleep < 60)
		return (0);
	else if (table->nb_philo > 200 || table->nb_philo == 0)
		return (0);
	return (1);
}

void	*runtime(void *param)
{
	t_table		**table;
	int			id;
	static int	i = 1;

	table = param;
	id = (*table)->philos->id[i];
	//(*table)->start_simulation = get_time();
	while (!(*table)->end_simulation)
	{
		(*table)->start_simulation = get_time();
		printf("%d philosopher %d" YELLOW " is thinking\n" RESET,
			(*table)->start_simulation, (*table)->philos->id[id]);
		ft_usleep(10);
		if ((*table)->philos->meals_counter == (*table)->must_eat)
		{
			printf("Le must_eat est satisfait\n");
			(*table)->end_simulation = true;
			exit(1);
		}
		pthread_mutex_lock(&(*table)->philos->right_fork->fork);
		printf("%d philosopher %d" RED " is eating\n" RESET,
			(*table)->start_simulation, (*table)->philos->id[id]);
		pthread_mutex_lock(&(*table)->philos->left_fork->fork);
		ft_usleep((*table)->time_to_eat);
		(*table)->philos->meals_counter++;
		pthread_mutex_unlock(&(*table)->philos->right_fork->fork);
		pthread_mutex_unlock(&(*table)->philos->left_fork->fork);
		printf("%d philosopher %d" BLUE " is sleeping\n" RESET,
			(*table)->start_simulation, (*table)->philos->id[id]);
		ft_usleep((*table)->time_to_sleep);
		i++;
	}
	pthread_exit(NULL);
}

void	create_thread(t_table **table)
{
	int	i;
	int	id;
	int	check;

	i = 0;
	id = 1;
	check = 0;
	(*table)->philos->thread_id = malloc(sizeof(t_table) * (*table)->nb_philo
			+ 1);
	while (i < (*table)->nb_philo + 1)
	{
		(*table)->philos->id[i] = id;
		check = pthread_create(&(*table)->philos->thread_id[i], NULL, runtime,
				table);
		if (check)
		{
			printf("Error creating thread");
			return ;
		}
		ft_usleep(50);
		id++;
		i++;
	}
}
