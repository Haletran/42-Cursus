/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 20:47:27 by codespace         #+#    #+#             */
/*   Updated: 2024/02/18 18:30:56 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	index_list(t_lst *stack, int index)
{
	t_lst	*current;
	int		smallest;

	current = stack;
	smallest = INT_MAX;
	while (current)
	{
		if (smallest >= current->content && current->index == 0)
			smallest = current->content;
		current = current->next;
	}
	current = stack;
	while (current->content != smallest)
		current = current->next;
	current->index = index;
}

void	ft_index(t_lst **a, int size, int flag)
{
	int	index;
	int	j;

	index = 1;
	j = 0;
	if (flag == 0)
		j = 1;
	while (j < size)
	{
		index_list(*a, index);
		index++;
		j++;
	}
}

t_lst	*init_stack(t_lst *a, int size, char **arr, int flag)
{
	t_lst	*start;
	int		tmp;

	start = NULL;
	tmp = 1;
	if (flag == 1)
		tmp = 0;
	while (tmp != size)
	{
		if (!a)
		{
			a = ft_lst_new(ft_atoi(arr[tmp]), 0);
			start = a;
		}
		else
		{
			while (a && a->next != NULL)
				a = a->next;
			ft_lstadd_back(a, ft_atoi(arr[tmp]));
		}
		tmp++;
	}
	a = start;
	ft_index(&a, size, flag);
	return (a);
}
