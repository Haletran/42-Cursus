/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 20:47:27 by codespace         #+#    #+#             */
/*   Updated: 2024/01/11 18:26:46 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	init_stack(node_t **head, int size, char **arr)
{
	int		i;
	node_t	*new_node;

	i = 1;
	if (size == 2)
	{
		size = get_args(arr);
		i = 0;
	}
	*head = NULL;
	while (i < size)
	{
		new_node = malloc(sizeof(node_t));
		if (new_node == NULL)
			return (0);
		new_node->content = ft_atoi(arr[i]);
		if (new_node->content >= INT_MAX || new_node->content <= INT_MIN
			|| ft_strlen(arr[i]) >= 11)
		{
			free(new_node);
			return (ft_error());
		}
		new_node->next = *head;
		*head = new_node;
		i++;
	}
	return (1);
}

void	sort_two_nodes(node_t **node1)
{
	node_t	*node2;
	int		temp;

	if (*node1 == NULL || node1 == NULL)
		return ;
	node2 = (*node1)->next;
	if ((*node1)->content < node2->content)
	{
		temp = (*node1)->content;
		(*node1)->content = node2->content;
		node2->content = temp;
		ft_putendl_fd("sa", 1);
	}
}
