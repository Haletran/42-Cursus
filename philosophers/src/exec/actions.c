/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:16:59 by bapasqui          #+#    #+#             */
/*   Updated: 2024/04/22 12:54:40 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void is_eating(t_philo *philo)
{
    philo->status = EATING;
    //pthread_mutex_lock(philo->fork);
    //pthread_mutex_lock(philo->next->fork);
    philo->eat_count += 1;
    print_status(philo);
    usleep(philo->infos->t_eat);
    //pthread_mutex_unlock(philo->fork);
    //pthread_mutex_unlock(philo->next->fork);
}


void is_thinking(t_philo *philo)
{
    philo->status = THINKING;
    print_status(philo);
    usleep(philo->infos->t_die);
}

void is_sleeping(t_philo *philo)
{
    philo->status = SLEEPING;
    print_status(philo);
    usleep(philo->infos->t_sleep);
}