/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:21:14 by bapasqui          #+#    #+#             */
/*   Updated: 2024/02/13 15:19:33 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ra(t_lst **a)
{
	t_lst	*head;
	t_lst	*to_free;
	int	tmp;
	int	tmp_index;

	if (*a == NULL || (*a)->next == NULL)
		return;

	tmp = (*a)->content;
	tmp_index = (*a)->index;
	head = (*a)->next;
	to_free = *a;

	while ((*a)->next != NULL)
		*a = (*a)->next;

	(*a)->next = ft_lst_new(tmp, tmp_index);
	*a = head;
	free(to_free);
	ft_putendl_fd("ra", 1);
}


void	rb(t_lst **a)
{
	t_lst	*head;
	t_lst	*to_free;
	int	tmp;
	int	tmp_index;

	if (*a == NULL || (*a)->next == NULL)
		return;

	tmp = (*a)->content;
	tmp_index = (*a)->index;
	head = (*a)->next;
	to_free = *a;

	while ((*a)->next != NULL)
		*a = (*a)->next;

	(*a)->next = ft_lst_new(tmp, tmp_index);
	*a = head;
	free(to_free);
	ft_putendl_fd("rb", 1);
}

