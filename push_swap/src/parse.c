/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 20:47:27 by codespace         #+#    #+#             */
/*   Updated: 2024/02/13 15:35:12 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// TODO: add check if the number is > MAX_INT or < MIN_INT or else

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

void ft_index(t_lst **a, int size)
{
	int	index;
	int	j;

	index = 1;
	j = 0;
	
	while (j < size - 1)
	{
		index_list(*a, index);
		index++;
		j++;
	}
}

t_lst	*init_stack(t_lst *a, int size, char **arr, int count)
{
	t_lst	*start;
	int		tmp;

	start = NULL;
	tmp = 0;
	while (count != size)
	{
		if (!a)
		{
			a = ft_lstnew(ft_atoi(arr[count]));
			start = a;
		}
		else
		{
			while (a && a->next != NULL)
				a = a->next;
			ft_lstadd_back(a, ft_atoi(arr[count]));
		}
		count++;
	}
	a = start;
	//ft_index(&a, size);
	return (a);
}
