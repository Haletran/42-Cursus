/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:04:51 by bapasqui          #+#    #+#             */
/*   Updated: 2024/04/24 13:51:17 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void destroy_mutex(t_philo *philo)
{
    t_philo *tmp;

    tmp = philo;
    while (1)
    {
        if (tmp->last == 1)
            break ;
        pthread_mutex_unlock(tmp->fork);
        pthread_mutex_destroy(tmp->fork);
        pthread_mutex_unlock(&tmp->infos->print_mutex);
        pthread_mutex_destroy(&tmp->infos->print_mutex);
        free(tmp->fork);
        tmp = tmp->next;
    }
    pthread_mutex_unlock(tmp->fork);
    pthread_mutex_destroy(tmp->fork);
    pthread_mutex_unlock(&tmp->infos->print_mutex);
    pthread_mutex_destroy(&tmp->infos->print_mutex);
    free(tmp->fork);
}



void ft_join(t_philo *philo)
{
    t_philo *tmp;

    tmp = philo;
	while (1)
	{
        if (tmp->last == 1)
            break ;
		pthread_join(tmp->philos, NULL);
		tmp = tmp->next;
	}
    pthread_join(tmp->philos, NULL);
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
        if (tmp->last == 1)
            break ;
        free(tmp);
        tmp = tmp->next;
    }
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
