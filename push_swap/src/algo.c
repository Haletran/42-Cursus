/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:35:58 by baptiste          #+#    #+#             */
/*   Updated: 2024/02/19 11:15:56 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_small_stack(t_lst **a)
{
	while (!is_sorted_list(a))
	{
		if ((*a)->content > (*a)->next->content)
			sa(a);
		else if ((*a)->content < (*a)->next->content)
			rra(a);
	}
}

void	sort_medium_stack(t_lst **a, t_lst **b)
{
	t_lst	*head;

	head = *a;
	while (!is_sorted_list(a))
	{
		while (ft_lst_size(head) != 3)
		{
			pb(a, b);
			head = *a;
		}
		sort_small_stack(a);
		if (*b != NULL)
			pa(a, b);
		if ((*a)->content > (*a)->next->content)
			sa(a);
	}
}

void	radix_sort(t_lst **a, t_lst **b)
{
	int		i;
	t_lst	*head;
	int		j;

	i = 0;
	head = *a;
	j = ft_lst_size(head);
	while (!is_sorted_list(a))
	{
		j = ft_lst_size(*a);
		while (j > 0)
		{
			if ((((*a)->index >> i) & 1) == 1)
				ra(a);
			else
				pb(a, b);
			j--;
		}
		while (ft_lst_size(*b) != 0)
			pa(a, b);
		i++;
	}
}

void	sort_five(t_lst **a, t_lst **b)
{
	while ((*a)->index != 1)
		rra(a);
	pb(a, b);
	while ((*a)->index != 2)
		rra(a);
	pb(a, b);
	sort_small_stack(a);
	pa(a, b);
	pa(a, b);
}

void	choose_sort(t_lst **a, t_lst **b, int size)
{
	if (size == 2)
		sa(a);
	else if (size == 3)
		sort_small_stack(a);
	else if (size == 4)
		sort_medium_stack(a, b);
	else if (size == 5)
		sort_five(a, b);
	else if (size >= 5)
		radix_sort(a, b);
}
