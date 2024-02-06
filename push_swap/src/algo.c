/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:35:58 by baptiste          #+#    #+#             */
/*   Updated: 2024/02/06 22:02:19 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted_list(t_lst **a)
{
	t_lst	*head;

	head = *a;
	while (head && head->next)
	{
		if (head->content > head->next->content)
			return (0);
		head = head->next;
	}
	return (1);
}

t_lst	**sort_small_stack(t_lst **a, t_lst **b, int size, int count)
{
	(void)b;
	if (count == 0)
		size += 1;
	if (size - 1 == 2)
		sa(*a);
	else if (size - 1 == 3)
	{
		while (!is_sorted_list(a))
		{
			if ((*a)->content > (*a)->next->content)
				sa(*a);
			else if ((*a)->content < (*a)->next->content)
				(*a) = rra(*a);
		}
	}
	else if (size - 1 == 4 || size - 1 == 5)
	{
		t_lst *head;
		head = *a;
		if ((*a)->content > (*a)->next->content)
			sa(*a);
		while (ft_lst_size(*a) != 3)
		{
			pb(a, b);
			*a = (*a)->next;
		}
		sort_small_stack(a, b, 4, count);
	}
	return (a);
}

void	sort_big_stack(t_lst *a, t_lst *b);