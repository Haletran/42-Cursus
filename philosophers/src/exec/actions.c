/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:16:59 by bapasqui          #+#    #+#             */
/*   Updated: 2024/04/22 15:54:12 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void is_eating(t_philo *philo)
{
    if (philo->infos->end_of_simulation != 1)
    {
        philo->status = EATING;
        pthread_mutex_lock(philo->fork);
        if (philo->infos->end_of_simulation == 1)
            return ;
        printf("%ld %d has taken a fork\n", actual_time() - philo->infos->start_time, philo->id);
        pthread_mutex_lock(philo->next->fork);
        if (philo->infos->end_of_simulation == 1)
            return ;
        printf("%ld %d has taken a fork\n", actual_time() - philo->infos->start_time, philo->id);
        philo->eat_count++;
        philo->last_meal = actual_time() - philo->infos->start_time;
        if (philo->eat_count == philo->infos->nb_meals)
            philo->is_full = true;
        print_status(philo);
        ft_usleep(philo->infos->t_eat);
        pthread_mutex_unlock(philo->fork);
        pthread_mutex_unlock(philo->next->fork);
    }
}


void is_thinking(t_philo *philo)
{
    if (philo->infos->end_of_simulation != 1)
    {
        philo->status = THINKING;
        print_status(philo);
    }
}

void is_sleeping(t_philo *philo)
{
    if (philo->infos->end_of_simulation != 1)
    {
        philo->status = SLEEPING;
        print_status(philo);
        ft_usleep(philo->infos->t_sleep);
    }
}