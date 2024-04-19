/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:21:03 by bapasqui          #+#    #+#             */
/*   Updated: 2024/04/19 16:20:26 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void print_lst(t_philo *philo)
{
    t_philo *tmp;

    tmp = philo;
    while (tmp)
    {
        printf("%d\n", tmp->id);
        tmp = tmp->next;
    }
}