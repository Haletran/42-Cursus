/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:35:58 by baptiste          #+#    #+#             */
/*   Updated: 2024/02/06 23:15:44 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted_list(t_lst **a, t_lst **b)
{
	t_lst	*head;

	if (a == NULL || *a == NULL)
	{
		return (0);
	}
	head = *a;
	(void)b;
	while (head && head->next)
	{
		if (head->content > head->next->content)
			return (0);
		head = head->next;
	}
	return (1);
}

void	sort_small_stack(t_lst **a, t_lst **b, int size, int count)
{
	t_lst	*head;

	(void)b;
	if (count == 0)
		size += 1;
	if (size - 1 == 2)
		sa(*a);
	else if (size - 1 == 3)
	{
		while (!is_sorted_list(a, b))
		{
			if ((*a)->content > (*a)->next->content)
				sa(*a);
			else if ((*a)->content < (*a)->next->content)
				(*a) = rra(*a);
		}
	}
	else if (size - 1 == 4)
	{
		head = *a;
		while (!is_sorted_list(a, b))
		{
			while (ft_lst_size(head) != 3)
			{
				pb(a, b);
				head = *a;
			}
			if (count == 0)
				sort_small_stack(a, b, size - 2, count);
			else
				sort_small_stack(a, b, size - 1, count);
			if (*b != NULL)
				pa(a, b);
			if ((*a)->content > (*a)->next->content)
				sa(*a);
		}
	}
}

void	sort_big_stack(t_lst *a, t_lst *b);