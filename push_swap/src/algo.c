/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptiste <baptiste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:35:58 by baptiste          #+#    #+#             */
/*   Updated: 2024/02/15 02:05:23 by baptiste         ###   ########.fr       */
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

/* void sort_five(t_lst **a, t_lst **b) 
{
    t_lst *head_a = *a;
    t_lst *prev_a = NULL;

    while ((*a)->index != 1) {
        prev_a = *a;
        *a = (*a)->next;
    }
    if ((*a)->index == 1) 
	{
        if (prev_a != NULL)
            prev_a->next = (*a)->next;
        else
            head_a = (*a)->next;
        pb(a, b);
    }
    *a = head_a;
	head_a = *a;
    prev_a = NULL;
	print_list("A\n", *a);
    while ((*a)->index != 2) {
        prev_a = *a;
        *a = (*a)->next;
    }
    if ((*a)->index == 2) 
	{
        if (prev_a != NULL)
            prev_a->next = (*a)->next;
        else
            head_a = (*a)->next;
        pb(a, b);
    }
    *a = head_a;
	if(!(is_sorted_list(a)))
		sort_small_stack(a);
	pa(a, b);
	pa(a, b);
} */

void sort_five(t_lst **a, t_lst **b)
{
	while ((*a)->index != 1)
		ra(a);
	pb(a, b);
	while ((*a)->index != 2)
		ra(a);
	pb(a, b);
	sort_small_stack(a);
	pa(a, b);
	pa(a, b);
}


void	choose_sort(t_lst **a, t_lst **b, int size)
{
	if (size - 1 == 2)
		sa(a);
	else if (size - 1 == 3)
		sort_small_stack(a);
	else if (size - 1 == 4)
		sort_medium_stack(a, b);
	else if (size - 1 == 5)
		sort_five(a, b);
	else if (size - 1 >= 5)
		radix_sort(a, b);
}
