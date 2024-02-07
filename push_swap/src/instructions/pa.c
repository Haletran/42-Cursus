/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 08:54:17 by codespace         #+#    #+#             */
/*   Updated: 2024/02/07 17:05:27 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	pb(t_lst **a, t_lst **b)
{
	t_lst	*afrique;

	afrique = (*a)->next;
	if (*b == NULL)
	{
		*b = ft_lstnew((**a).content);
		free(*a);
		*a = afrique;
	}
	else
		ft_lst_add_front(b, *a);
	*a = afrique;
	ft_putendl_fd("pb", 1);
}

void	pa(t_lst **a, t_lst **b)
{
	t_lst	*afrique;

	afrique = (*b)->next;
	if (*a == NULL)
	{
		*a = ft_lstnew((**b).content);
		free(*b);
		*b = afrique;
	}
	else
		ft_lst_add_front(a, *b);
	*b = afrique;
	ft_putendl_fd("pa", 1);
}
