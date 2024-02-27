/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:00:02 by bapasqui          #+#    #+#             */
/*   Updated: 2024/02/27 17:23:01 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	init_value(t_table **table, char **arr)
{
	(*table)->nb_philo = ft_atoi(arr[1]);
	(*table)->philos = malloc(sizeof(t_table));
	(*table)->time_to_die = ft_atoi(arr[2]);
	(*table)->time_to_eat = ft_atoi(arr[3]);
	(*table)->time_to_sleep = ft_atoi(arr[4]);
	if (arr[5])
		(*table)->must_eat = ft_atoi(arr[5]);
	(*table)->philos->id = malloc(sizeof(t_table) * (*table)->nb_philo + 1);
	(*table)->philos->right_fork = malloc(100);
	(*table)->philos->left_fork = malloc(100);

	pthread_mutex_init(&(*table)->philos->right_fork->fork, NULL);
	pthread_mutex_init(&(*table)->philos->left_fork->fork, NULL);
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
	int id = 0;
	static int i = 1;

	table = param;
	id = (*table)->philos->id[i];
	while (!(*table)->end_simulation)
	{
		printf("philosopher %d" YELLOW " is thinking\n" RESET, (*table)->philos->id[id]);
		usleep(500);

		pthread_mutex_lock(&(*table)->philos->right_fork->fork);
		pthread_mutex_lock(&(*table)->philos->left_fork->fork);

		printf("philosopher %d" RED " is eating\n" RESET, (*table)->philos->id[id]);
		usleep((*table)->time_to_eat);

		pthread_mutex_unlock(&(*table)->philos->right_fork->fork);
		pthread_mutex_unlock(&(*table)->philos->left_fork->fork);

		printf("philosopher %d" BLUE " is sleeping\n" RESET, (*table)->philos->id[id]);
		usleep((*table)->time_to_sleep);
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
		check = pthread_create(&(*table)->philos->thread_id[i], NULL, runtime,
				table);
		if (check)
		{
			printf("Error creating thread");
			return ;
		}
		(*table)->philos->id[i] = id;
		usleep(50);
		id++;
		i++;
	}
}
