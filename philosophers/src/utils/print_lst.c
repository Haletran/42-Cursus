/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:21:03 by bapasqui          #+#    #+#             */
/*   Updated: 2024/04/22 15:37:42 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void print_lst(t_philo *philo)
{
    t_philo *tmp;

    tmp = philo;
    while (1)
    {
        printf("philo = %p\n", tmp);
        printf("ID = %d\n", tmp->id);
        printf("last = %d\n", tmp->last);
        printf("prev = %p\n", tmp->prev);
        printf("next = %p\n", tmp->next);
        if (tmp->last == 1)
            break ;
        tmp = tmp->next;
    }
}

void print_info(t_infos *infos)
{
    printf("nb_philo = %d\n", infos->nb_philo);
    printf("t_die = %d\n", infos->t_die);
    printf("t_eat = %d\n", infos->t_eat);
    printf("t_sleep = %d\n", infos->t_sleep);
    printf("nb_meals = %d\n", infos->nb_meals);
    printf("start_time = %ld\n", infos->start_time);
    printf("end_of_simulation = %d\n", infos->end_of_simulation);
}