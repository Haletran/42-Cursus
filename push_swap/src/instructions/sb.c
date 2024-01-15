/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:49:56 by codespace         #+#    #+#             */
/*   Updated: 2024/01/15 12:01:31 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// TODO: Why making sb if it is the same as sa but with b pile
void	sb(node_t **node1)
{
	node_t *node2;
	int	temp;

	if (*node1 == NULL || node1 == NULL)
		return ;
	node2 = (*node1)->next;
	if ((*node1)->content < node2->content)
	{
		temp = (*node1)->content;
		(*node1)->content = node2->content;
		node2->content = temp;
		ft_putendl_fd("sb", 1);
	}
}