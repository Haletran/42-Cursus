/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:21:03 by bapasqui          #+#    #+#             */
/*   Updated: 2024/04/22 12:22:01 by bapasqui         ###   ########.fr       */
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