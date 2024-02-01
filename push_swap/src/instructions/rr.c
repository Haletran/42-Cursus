/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:21:14 by bapasqui          #+#    #+#             */
/*   Updated: 2024/02/01 19:09:40 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void ra(t_lst **a)
{
    t_lst *head;
    int tmp;
    tmp = (*a)->content;
    head = (*a)->next;
    while((*a)->next != NULL)
        (*a) = (*a)->next;
    (*a)->next = ft_lstnew(tmp);
    (*a) = head;
    ft_putendl_fd("ra", 1);
}
