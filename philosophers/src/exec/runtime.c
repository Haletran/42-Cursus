/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runtime.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:01:30 by bapasqui          #+#    #+#             */
/*   Updated: 2024/04/25 16:22:04 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	*routine(void *params)
{
	t_philo	*philo;

	philo = params;
	while (1)
	{
		if (philo->id % 2 == 0)
			ft_usleep(10);
		if (is_eating(philo) == END_OF_SIMULATION)
			break ;
		if (is_sleeping(philo) == END_OF_SIMULATION)
			break ;
		if (is_thinking(philo) == END_OF_SIMULATION)
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
		if (check_fullness(philos) == END_OF_SIMULATION)
			break ;
		if (check_end_simulation(philos) == END_OF_SIMULATION)
			break ;
	}
	return (SUCCESS);
}

int	setup_philo(t_table *table)
{
	t_philo	*head;
	int		i;

	head = table->philo;
	i = 0;
	table->server->monitor = ft_calloc(table->infos->nb_philo,
			sizeof(pthread_t));
	while (1)
	{
		if (pthread_create(&head->philos, NULL, routine, head) != 0)
			return (FAILURE);
		if (pthread_create(&table->server->monitor[i], NULL, monitoring,
				head) != 0)
			return (FAILURE);
		if (head->last == 1)
			break ;
		head = head->next;
		i++;
	}
	return (SUCCESS);
}
