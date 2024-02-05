/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:35:58 by baptiste          #+#    #+#             */
/*   Updated: 2024/02/05 16:09:07 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int is_sorted_list(t_lst **a)
{
	t_lst *head;

	head = *a;
	while (head && head->next)
	{
		if (head->content > head->next->content)
			return (0);
		head = head->next;
	}
	return (1);
}

t_lst	**sort_small_stack(t_lst **a, t_lst **b, int size)
{
    (void)b;
	if (size - 1 == 2)
		sa(*a);
	else if (size - 1 == 3)
	{
		while (!is_sorted_list(a))
		{
            //print_list("A :", *a);
			if ((*a)->content > (*a)->next->content)
				sa(*a);
			else if ((*a)->content < (*a)->next->content)
				(*a) = rra(*a);
            //sleep(1);
		}
	}
	return (a);
}

void		sort_big_stack(t_lst *a, t_lst *b);