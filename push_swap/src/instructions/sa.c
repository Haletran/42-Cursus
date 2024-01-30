/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:45:47 by codespace         #+#    #+#             */
/*   Updated: 2024/01/26 15:38:46 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sa(node_t **node1)
{
	node_t *node2;
	int temp;

	if (*node1 == NULL || node1 == NULL)
		return ;
	node2 = (*node1)->next;
	temp = (*node1)->content;
	(*node1)->content = node2->content;
	node2->content = temp;
	ft_putendl_fd("sa", 1);
}