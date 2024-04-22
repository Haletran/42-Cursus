/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:04:51 by bapasqui          #+#    #+#             */
/*   Updated: 2024/04/22 12:27:04 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void ft_join(t_philo *philo)
{
	while (1)
	{
        if (philo->last == 1)
            break ;
		pthread_join(philo->philos, NULL);
		philo = philo->next;
	}
}

void ft_free_lst(t_philo *philo)
{
    t_philo *tmp;

    while (1)
    {
        tmp = philo;
        if (philo->last == 1)
            break ;
        philo = philo->next;
        free(tmp->fork);
        free(tmp);
    }
    free(tmp->fork);
    free(tmp);
}

void	ft_free(t_table **table)
{
    ft_join((*table)->philo);
    free((*table)->infos);
    free((*table)->server);
    ft_free_lst((*table)->philo);
    free(*table);
}