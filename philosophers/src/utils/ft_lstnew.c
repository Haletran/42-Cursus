/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:41:44 by bapasqui          #+#    #+#             */
/*   Updated: 2024/04/22 12:20:10 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	*ft_lst_new(int content, t_table *table)
{
	t_philo	*philo;

	philo = ft_calloc(1, sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->id = content;
    philo->philos = 0;
    philo->infos = table->infos;
    philo->fork = ft_calloc(1, sizeof(pthread_mutex_t));
    pthread_mutex_init(philo->fork, NULL);
    philo->time = 0;
	philo->prev = NULL;
	philo->last = 1;
	philo->next = NULL;
	return (philo);
}