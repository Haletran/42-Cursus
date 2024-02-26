/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:00:02 by bapasqui          #+#    #+#             */
/*   Updated: 2024/02/26 18:52:09 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	init_value(t_table **table, char **arr)
{
    (*table)->philos = malloc(100);
	(*table)->nb_philo = ft_atoi(arr[1]);
	(*table)->time_to_die = ft_atoi(arr[2]);
	(*table)->time_to_eat = ft_atoi(arr[3]);
	(*table)->time_to_sleep = ft_atoi(arr[4]);
	if (arr[5])
		(*table)->must_eat = ft_atoi(arr[5]);
    (*table)->philos->id = malloc(100);
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

static void	*runtime()
{
	pthread_t	tid;

	tid = pthread_self();
	printf("PHILO created with id: %lu\n", (unsigned long)tid);
	return (NULL);
}

void create_thread(t_table **table)
{
    int i;
    int id;
    int check;

    i = 0;
    id = 1;
    check = 0;
    (*table)->philos->thread_id = malloc(sizeof(t_table) * (*table)->nb_philo);
    while (i < (*table)->nb_philo + 1)
    {
        check = pthread_create(&(*table)->philos->thread_id[i], NULL, runtime, NULL);
        (*table)->philos->id[i] = id;
        usleep(50);
        id++;
        i++;
    }
    printf("-> %d threads created\n", i);
}
