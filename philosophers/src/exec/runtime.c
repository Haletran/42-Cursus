/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runtime.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:01:30 by bapasqui          #+#    #+#             */
/*   Updated: 2024/04/24 15:46:29 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	*routine(void *params)
{
	t_philo	*philo;
	
	philo = params;
	while(1)
	{
		if (philo->id % 2 == 0)
			ft_usleep(10);
		if (is_eating(philo) == END_OF_SIMULATION)
			break ;
		if (is_sleeping(philo) == END_OF_SIMULATION)
			break;
		if (is_thinking(philo) == END_OF_SIMULATION)
			break;
	}
	return (SUCCESS);
}

void	*monitoring(void *params)
{
	t_philo	*philos;

	philos = params;
	while(1)
	{
		pthread_mutex_lock(&philos->infos->print_mutex);
		if ((actual_time() - philos->infos->start_time) - philos->last_meal > philos->infos->t_die)
		{
			if (philos->infos->end_of_simulation != 1)
			{
				philos->status = DEAD;
				philos->infos->end_of_simulation = 1;
				print_status(philos);
				pthread_mutex_unlock(&philos->infos->print_mutex);
				break ;
			}
		}
		pthread_mutex_unlock(&philos->infos->print_mutex);
		pthread_mutex_lock(&philos->infos->print_mutex);
		if (philos->is_full == true && philos->check == false)
		{
			philos->check = true;
			philos->infos->counter++;
			if (philos->infos->counter == philos->infos->nb_philo)
			{
				philos->infos->end_of_simulation = 1;
				pthread_mutex_unlock(&philos->infos->print_mutex);
				break ;
			}
		}
		pthread_mutex_unlock(&philos->infos->print_mutex);
		pthread_mutex_lock(&philos->infos->print_mutex);
		if (philos->infos->end_of_simulation == 1)
		{
			pthread_mutex_unlock(&philos->infos->print_mutex);
			break ;
		}
		pthread_mutex_unlock(&philos->infos->print_mutex);
	}
	return (SUCCESS);
}

int	setup_philo(t_table *table)
{
	t_philo *head;

	head = table->philo;
	while (1)
	{
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