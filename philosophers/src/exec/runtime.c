/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runtime.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:01:30 by bapasqui          #+#    #+#             */
/*   Updated: 2024/05/02 20:22:12 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	*routine(void *params)
{
	t_philo	*philo;

	philo = params;
	if (philo->id % 2 == 0)
		ft_usleep(10);
	while (1)
	{
		if (is_eating(philo) == END_OF_SIMULATION)
			break ;
		else if (is_sleeping(philo) == END_OF_SIMULATION)
			break ;
		else if (is_thinking(philo) == END_OF_SIMULATION)
			break ;
	}
	return (SUCCESS);
}

void	*monitoring(void *params)
{
	t_philo	*philos;

	philos = params;
	while (1)
	{
		if (check_death(philos) == END_OF_SIMULATION)
			break ;
		else if (check_fullness(philos) == END_OF_SIMULATION)
			break ;
		else if (check_end_simulation(philos) == END_OF_SIMULATION)
			break ;
		philos = philos->next;
	}
	return (SUCCESS);
}

int	setup_philo(t_table *table)
{
	t_philo	*head;

	head = table->philo;
	table->server->monitor = 0;
	while (1)
	{
		if (pthread_create(&head->philos, NULL, routine, head) != 0)
			return (FAILURE);
		if (head->last == 1)
			break ;
		head = head->next;
	}
	if (pthread_create(&table->server->monitor, NULL, monitoring, head) != 0)
		return (FAILURE);
	return (SUCCESS);
}
