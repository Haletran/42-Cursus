/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:16:59 by bapasqui          #+#    #+#             */
/*   Updated: 2024/04/19 18:21:37 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void *is_eating(t_philo *philo)
{
    philo->status = EATING;
    //mutex
    philo->eat_count += 1;
    print_status(philo);
    //usleep()
    // unlock
}


void *is_thinking(t_philo *philo)
{
    philo->status = THINKING;
    // mutex
    print_status(philo);
    //usleep()
    //unlock



}

void *is_sleeping(t_philo *philo)
{
    philo->status = SLEEPING;
    // mutex
    print_status(philo);
    //usleep()
    //unlock
}