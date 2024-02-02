/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:14:50 by baptiste          #+#    #+#             */
/*   Updated: 2024/02/02 13:05:04 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_lst	*rra(t_lst *a)
{
	t_lst	*head;
	t_lst	*second_last;

	head = a;
	while (a->next != NULL)
	{
		second_last = a;
		a = a->next;
	}
	a->next = head;
	second_last->next = NULL;
	ft_putendl_fd("rra", 1);
	return (a);
}

t_lst	*rrb(t_lst *b)
{
	t_lst	*head;
	t_lst	*second_last;

	head = b;
	while (b->next != NULL)
	{
		second_last = b;
		b = b->next;
	}
	b->next = head;
	second_last->next = NULL;
	ft_putendl_fd("rrb", 1);
	return (b);
}
