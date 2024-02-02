/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:21:14 by bapasqui          #+#    #+#             */
/*   Updated: 2024/02/02 13:31:52 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_lst	*ra(t_lst *a)
{
	t_lst	*head;
	t_lst	*to_free;
	int		tmp;

	tmp = a->content;
	head = a->next;
	to_free = a;
	while (a->next != NULL)
		a = a->next;
	a->next = ft_lstnew(tmp);
	a = head;
	free(to_free);
	ft_putendl_fd("ra", 1);
	return (a);
}

t_lst	*rb(t_lst *b)
{
	t_lst	*head;
	t_lst	*to_free;
	int		tmp;

	tmp = b->content;
	head = b->next;
	to_free = b;
	while (b->next != NULL)
		b = b->next;
	b->next = ft_lstnew(tmp);
	b = head;
	free(to_free);
	ft_putendl_fd("rb", 1);
	return (b);
}
