/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:21:14 by bapasqui          #+#    #+#             */
/*   Updated: 2024/02/01 19:02:10 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void ra(t_lst **a)
{
    t_lst *head;
    t_lst *tmp;
    tmp = (*a);
    head = (*a)->next;
    tmp->next = NULL;
    while((*a)->next != NULL)
        (*a) = (*a)->next;
    (*a)->next = tmp;
    (*a) = head;
    ft_putendl_fd("ra", 1);
}
