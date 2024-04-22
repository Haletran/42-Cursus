/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:25:33 by bapasqui          #+#    #+#             */
/*   Updated: 2024/04/22 12:12:58 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void print_status(t_philo *philos)
{
    if (philos->status == EATING)
        printf("time %d is eating\n", philos->id);
    else if (philos->status == SLEEPING)
        printf("time %d is sleeping\n", philos->id);
    else if (philos->status == THINKING)
        printf("time %d is thinking\n", philos->id);
    else if (philos->status == DEAD)
        printf("time %d is dead\n", philos->id);
}  