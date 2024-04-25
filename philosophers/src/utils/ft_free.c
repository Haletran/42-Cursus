/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:04:51 by bapasqui          #+#    #+#             */
/*   Updated: 2024/04/25 16:10:24 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	ft_join(t_table *table)
{
	t_philo	*philo;

	philo = table->philo;
	while (1)
	{
		pthread_join(philo->philos, NULL);
		free(philo->fork);
		if (philo->last == 1)
			break ;
		philo = philo->next;
	}
}

void	ft_join_server(t_table *table)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = table->philo;
	while (1)
	{
		pthread_join(table->server->monitor[i], NULL);
		if (philo->last == 1)
			break ;
		philo = philo->next;
		i++;
	}
	free(table->server->monitor);
}

void	ft_free_lst(t_philo *philo)
{
	t_philo	*tmp;

	while (philo->last != 1)
	{
		tmp = philo;
		philo = philo->next;
		free(tmp);
	}
	free(philo);
}

void	ft_free(t_table **table)
{
	ft_join((*table));
	ft_join_server((*table));
	ft_free_lst((*table)->philo);
	free((*table)->server);
	free((*table)->infos);
	free((*table));
}
