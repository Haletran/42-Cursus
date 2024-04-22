/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runtime.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:01:30 by bapasqui          #+#    #+#             */
/*   Updated: 2024/04/22 12:54:20 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

// %  2 = impair
// si impair on commence par pair
// si pair on commence par impair
void	*routine(void *params)
{
	t_philo	*philo;
	t_philo *head;
	
	philo = params;
	head = philo;
	philo->time = 0;
	while(1)
	{
		if (philo->infos->end_of_simulation == 1)
			break ;
		is_eating(philo);
		is_sleeping(philo);
		is_thinking(philo);
		usleep(100);
	}
	return (SUCCESS);
}

void	*monitoring(void *params)
{
	t_philo	*philos;
	t_monitor *server;

	philos = params;
	server = ft_calloc(1, sizeof(t_monitor));
	pthread_mutex_init(&server->print_mutex, NULL);
	while(1)
	{
		if (philos->time > philos->infos->t_eat)
		{
			philos->status = DEAD;
			philos->infos->end_of_simulation = 1;
			pthread_mutex_lock(&server->print_mutex);
			print_status(philos);
			pthread_mutex_unlock(&server->print_mutex);
			break ;
		}
		if (philos->eat_count == philos->infos->nb_meals)
		{
			if (server->nb_meals == philos->eat_count)
				server->nb_meals += 1;
			else if (server->nb_meals == philos->infos->nb_meals)
			{
				philos->infos->end_of_simulation = 1;
				break;
			}
		}	
		usleep(100);
	}
	pthread_mutex_destroy(&server->print_mutex);
	return (SUCCESS);
}

int	setup_philo(t_table *table)
{
	t_philo *head;
	t_philo *tmp;

	head = table->philo;
	tmp = head;
	while (head)
	{
		if (pthread_create(&head->philos, NULL, routine, head) != 0)
			return (FAILURE);
		if (head->id % 2 == 0 || head->infos->nb_philo % 2 != 0)
			usleep(20);
		else
			usleep(40);
		if (pthread_create(&table->server->monitor, NULL, monitoring, head) != 0)
			return (FAILURE);
		head = head->next;
	}
	return (SUCCESS);
}