/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:00:02 by bapasqui          #+#    #+#             */
/*   Updated: 2024/02/27 14:59:22 by bapasqui         ###   ########.fr       */
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

static void	*runtime(void *param)
{
	t_table		**table;
	static int	i = 1;

	table = param;
	while (!(*table)->end_simulation)
	{
		printf("philosopher %d is thinking\n", (*table)->philos->id[i]);
		usleep(500);
		printf("philosopher %d is eating\n", (*table)->philos->id[i]);
		usleep((*table)->time_to_eat);
		// mutex des fourchettes
		printf("philosopher %d is sleeping\n", (*table)->philos->id[i]);
		usleep((*table)->time_to_sleep);
		// liberer les mutexs
	}
	i++;
	return (NULL);
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
		usleep(500);
		id++;
		i++;
	}
}
