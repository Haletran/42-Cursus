/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 08:54:17 by codespace         #+#    #+#             */
/*   Updated: 2024/02/15 15:34:40 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	pb(t_lst **a, t_lst **b)
{
	t_lst	*to_free;

	to_free = (*a)->next;
	if (*b == NULL)
	{
		*b = ft_lst_new((**a).content, (**a).index);
		free(*a);
		*a = to_free;
	}
	else
		ft_lst_add_front(b, *a);
	*a = to_free;
	ft_putendl_fd("pb", 1);
}

void	pa(t_lst **a, t_lst **b)
{
	t_lst	*to_free;

	to_free = (*b)->next;
	if (*a == NULL)
	{
		*a = ft_lst_new((**a).content, (**a).index);
		free(*b);
		*b = to_free;
	}
	else
		ft_lst_add_front(a, *b);
	*b = to_free;
	ft_putendl_fd("pa", 1);
}
