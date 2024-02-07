/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:35:58 by baptiste          #+#    #+#             */
/*   Updated: 2024/02/07 18:22:11 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted_list(t_lst **a)
{
	t_lst	*head;

	if (a == NULL || *a == NULL)
		return (0);
	head = *a;
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
	else if (size - 1 == 4)
		sort_medium_stack(a, b, size, count);
}

void	sort_medium_stack(t_lst **a, t_lst **b, int size, int count)
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
		sort_small_stack(a, b, size - 1, count);
		if (*b != NULL)
			pa(a, b);
		if ((*a)->content > (*a)->next->content)
			sa(*a);
	}
}

void	sort_big_stack(t_lst **a, t_lst **b)
{
	int		tmp;
	t_lst	*head;
	t_lst	*start;
	int		i;

	head = *a;
	start = *a;
	i = 0;
	tmp = ft_lst_size(*a);
	while (i != tmp / 2)
	{
		head = head->next;
		i++;
	}
	while ((*a)->content < head->content)
	{
		pb(a, b);
		*a = (*a)->next;
	}
	//*a = start;
	print_list("A\n", *a);
	print_list("B\n", *b);
	// ft_printf("%d", tmp);
}

