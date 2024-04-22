/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:25:33 by bapasqui          #+#    #+#             */
/*   Updated: 2024/04/22 14:40:48 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void print_status(t_philo *philos)
{
    pthread_mutex_lock(&philos->infos->print_mutex);
    if (philos->status == EATING)
        printf("%ld %d "YELLOW"is eating\n"RESET, actual_time() - philos->infos->start_time, philos->id);
    else if (philos->status == SLEEPING)
        printf("%ld %d "GREEN"is sleeping\n"RESET, actual_time() - philos->infos->start_time, philos->id);
    else if (philos->status == THINKING)
        printf("%ld %d "CYAN"is thinking\n"RESET, actual_time() - philos->infos->start_time, philos->id);
    else if (philos->status == DEAD)
        printf("%ld %d is dead\n", actual_time() - philos->infos->start_time, philos->id);
    pthread_mutex_unlock(&philos->infos->print_mutex);
}  