/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runtime.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:01:30 by bapasqui          #+#    #+#             */
/*   Updated: 2024/04/22 16:18:18 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	*routine(void *params)
{
	t_philo	*philo;
	
	philo = params;
	while(philo->infos->end_of_simulation != 1)
	{
		is_eating(philo);
		is_sleeping(philo);
		is_thinking(philo);
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
		if ((actual_time() - philos->infos->start_time) - philos->last_meal > philos->infos->t_die)
		{
			if (philos->infos->end_of_simulation != 1)
			{
				pthread_mutex_lock(&server->print_mutex);
				philos->status = DEAD;
				philos->infos->end_of_simulation = 1;
				print_status(philos);
				pthread_mutex_unlock(&server->print_mutex);
				break ;
			}
		}
		if (philos->is_full == true && philos->check == false)
		{
			pthread_mutex_lock(&server->print_mutex);
			philos->check = true;
			philos->infos->counter++;
			if (philos->infos->counter == philos->infos->nb_philo)
			{
				philos->infos->end_of_simulation = 1;
				break ;
			}
			pthread_mutex_unlock(&server->print_mutex);
		}
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
	while (1)
	{
		if (head->id % 2 == 0 || head->infos->nb_philo % 2 != 0)
			ft_usleep(20);
		if (pthread_create(&head->philos, NULL, routine, head) != 0)
			return (FAILURE);
		if (pthread_create(&table->server->monitor, NULL, monitoring, head) != 0)
			return (FAILURE);
		if (head->last == 1)
			break ;
		head = head->next;
	}
	return (SUCCESS);
}