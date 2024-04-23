/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:04:51 by bapasqui          #+#    #+#             */
/*   Updated: 2024/04/23 13:18:21 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

#include "../../includes/philo.h"

void ft_join(t_philo *philo)
{
	while (1)
	{
        if (philo->last == 1)
            break ;
		pthread_join(philo->philos, NULL);
        free(philo->fork);
        //pthread_mutex_destroy(&philo->infos->print_mutex);
		philo = philo->next;
	}
    pthread_join(philo->philos, NULL);
}

void ft_join_server(t_table *table)
{
    t_philo *philo;

    philo = table->philo;
    while(1)
    {
        if (philo->last == 1)
            break ;
        pthread_join(table->server->monitor, NULL);
        philo = philo->next;
    }
    pthread_join(table->server->monitor, NULL);
}


void ft_free_lst(t_philo *philo)
{
    t_philo *tmp;

    tmp = philo;
    while (1)
    {
        if (philo->last == 1)
            break ;
        pthread_mutex_destroy(tmp->fork);
        free(tmp->fork);
        pthread_mutex_destroy(&tmp->infos->print_mutex);
        free(tmp);
        tmp = tmp->next;
    }
    free(tmp->fork);
    free(tmp);
}

void	ft_free(t_table **table)
{
    ft_join((*table)->philo);
    ft_join_server((*table));
    free((*table)->infos);
    free((*table)->server);
    ft_free_lst((*table)->philo);
    free((*table));
}
