/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 20:47:27 by codespace         #+#    #+#             */
/*   Updated: 2024/02/14 02:06:47 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static long long	ft_atoi_test(const char *str, t_lst *a, char **arr)
{
	int			c;
	int			d;
	long long	e;
	char		oe;

	c = 0;
	oe = 1;
	d = 0;
	e = 0;
	if ((str[c] == 43 || str[c] == 45) && !(str[c + 1] >= '0' && str[c \
			+ 1] <= '9'))
		ft_freeror(&a, arr);
	while (str[c] == 32 || (str[c] >= 9 && str[c] <= 13))
		c++;
	if (str[c] == 43 || str[c] == 45)
		if (str[c++] == 45)
			oe = -1;
	while (str[c] >= '0' && str[c] <= '9')
	{
		e = e * 10 + str[c] - '0';
		c++;
	}
	if ((e * oe) > INT_MAX || (e * oe) < INT_MIN)
		ft_freeror(&a, arr);
	return (e * oe);
}

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

void	ft_index(t_lst **a, int size, int tmp)
{
	int	index;
	int	j;

	index = 1;
	j = 0;
	if (tmp == 0)
		size += 1;
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
	tmp = count;
	while (count != size)
	{
		if (!a)
		{
			a = ft_lstnew(ft_atoi_test(arr[count], a, arr));
			start = a;
		}
		else
		{
			while (a && a->next != NULL)
				a = a->next;
			ft_lstadd_back(a, ft_atoi_test(arr[count], start, arr));
		}
		count++;
	}
	a = start;
	ft_index(&a, size, tmp);
	return (a);
}
