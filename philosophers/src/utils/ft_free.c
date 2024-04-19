/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:04:51 by bapasqui          #+#    #+#             */
/*   Updated: 2024/04/19 16:20:42 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void ft_join(t_philo *philo)
{
	while (philo)
	{
		pthread_join(philo->philos, NULL);
		philo = philo->next;
	}
}

void ft_free_lst(t_philo *philo)
{
    t_philo *tmp;

    while (philo)
    {
        tmp = philo;
        philo = philo->next;
        free(tmp->fork);
        free(tmp);
    }
}

void	ft_free(t_table **table)
{
    ft_join((*table)->philo);
    free((*table)->infos);
    ft_free_lst((*table)->philo);
    free(*table);
}
