/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:16:59 by bapasqui          #+#    #+#             */
/*   Updated: 2024/04/24 15:33:37 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int is_eating(t_philo *philo)
{
    pthread_mutex_lock(philo->fork);
    pthread_mutex_lock(&philo->infos->print_mutex);
    if (philo->infos->end_of_simulation == 1)
    {
        pthread_mutex_unlock(philo->fork);
        pthread_mutex_unlock(&philo->infos->print_mutex);
        return (END_OF_SIMULATION);
    }
    printf("%ld %d has taken a fork\n", actual_time() - philo->infos->start_time, philo->id);
    pthread_mutex_unlock(&philo->infos->print_mutex);
    pthread_mutex_lock(philo->next->fork);
    pthread_mutex_lock(&philo->infos->print_mutex);
    if (philo->infos->end_of_simulation == 1)
    {
        pthread_mutex_unlock(philo->fork);
        return (END_OF_SIMULATION);
    }
    printf("%ld %d has taken a fork\n", actual_time() - philo->infos->start_time, philo->id);
    pthread_mutex_unlock(&philo->infos->print_mutex);
    pthread_mutex_lock(&philo->infos->print_mutex);
    if (philo->infos->end_of_simulation == 1)
    {
        pthread_mutex_unlock(philo->fork);
        pthread_mutex_unlock(philo->next->fork);
        pthread_mutex_unlock(&philo->infos->print_mutex);
        return (END_OF_SIMULATION);
    }
    pthread_mutex_unlock(&philo->infos->print_mutex);
    pthread_mutex_lock(&philo->infos->print_mutex);
    philo->status = EATING;
    philo->eat_count++;
    philo->last_meal = actual_time() - philo->infos->start_time;
    if (philo->eat_count == philo->infos->nb_meals)
        philo->is_full = true;
    print_status(philo);
    pthread_mutex_unlock(&philo->infos->print_mutex);
    ft_usleep(philo->infos->t_eat);
    pthread_mutex_unlock(philo->fork);
    pthread_mutex_unlock(philo->next->fork);
    pthread_mutex_lock(&philo->infos->print_mutex);
    if (philo->infos->end_of_simulation == 1)
    {
        pthread_mutex_unlock(&philo->infos->print_mutex);
        return (END_OF_SIMULATION);
    }
    pthread_mutex_unlock(&philo->infos->print_mutex);
    return (SUCCESS);
}


int is_thinking(t_philo *philo)
{
    pthread_mutex_lock(&philo->infos->print_mutex);
    if (philo->infos->end_of_simulation == 1)
    {
        pthread_mutex_unlock(&philo->infos->print_mutex);
        return (END_OF_SIMULATION);
    }
    philo->status = THINKING;
    print_status(philo);
    pthread_mutex_unlock(&philo->infos->print_mutex);
    return (SUCCESS);
}

int is_sleeping(t_philo *philo)
{
    pthread_mutex_lock(&philo->infos->print_mutex);
    if (philo->infos->end_of_simulation == 1)
    {
        pthread_mutex_unlock(&philo->infos->print_mutex);
        return (END_OF_SIMULATION);
    }
    philo->status = SLEEPING;
    print_status(philo);
    pthread_mutex_unlock(&philo->infos->print_mutex);
    ft_usleep(philo->infos->t_sleep);
    return (SUCCESS);
}