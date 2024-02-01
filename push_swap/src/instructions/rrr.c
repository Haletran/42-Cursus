/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptiste <baptiste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:14:50 by baptiste          #+#    #+#             */
/*   Updated: 2024/02/01 21:35:29 by baptiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_lst *rra(t_lst *a)
{
    t_lst *head;
    t_lst *secondLast;

    head = a;
    while (a->next != NULL) 
    {
        secondLast = a;
        a = a->next;
    }
    a->next = head;
    secondLast->next = NULL;
    ft_putendl_fd("rra", 1);
    return (a);
}

t_lst *rrb(t_lst *b)
{
    t_lst *head;
    t_lst *secondLast;

    head = b;
    while (b->next != NULL) 
    {
        secondLast = b;
        b = b->next;
    }
    b->next = head;
    secondLast->next = NULL;
    ft_putendl_fd("rrb", 1);
    return (b);
}
