/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:14:50 by baptiste          #+#    #+#             */
/*   Updated: 2024/02/14 14:31:55 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rra(t_lst **a)
{
	t_lst	*head;
	t_lst	*second_last;

	head = *a;
	while ((*a)->next != NULL)
	{
		second_last = *a;
		*a = (*a)->next;
	}
	(*a)->next = head;
	second_last->next = NULL;
	ft_putendl_fd("rra", 1);
}

void	rrb(t_lst **a)
{
	t_lst	*head;
	t_lst	*second_last;

	head = *a;
	while ((*a)->next != NULL)
	{
		second_last = *a;
		*a = (*a)->next;
	}
	(*a)->next = head;
	second_last->next = NULL;
	ft_putendl_fd("rrb", 1);
}
