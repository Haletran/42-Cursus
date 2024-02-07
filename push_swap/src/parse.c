/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptiste <baptiste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 20:47:27 by codespace         #+#    #+#             */
/*   Updated: 2024/02/07 22:39:56 by baptiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// TODO: add check if the number is > MAX_INT or < MIN_INT or else

t_lst	*init_stack(t_lst *a, int size, char **arr, int count)
{
	t_lst	*start;
	int tmp;
	start = NULL;

	tmp = 0;
	while (count != size)
	{
		if (!a)
		{
			a = ft_lstnew(ft_atoi(arr[count]));
			start = a;
			a->index = tmp++;
		}
		else
		{
			while (a && a->next != NULL)
				a = a->next;
			ft_lstadd_back(a, ft_atoi(arr[count]));
			a->index = tmp++;
		}
		count++;
	}
	a->next->index = tmp++;
	a = start;
	return (a);
}
