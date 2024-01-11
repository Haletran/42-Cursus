/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 20:47:27 by codespace         #+#    #+#             */
/*   Updated: 2024/01/11 15:32:02 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	init_stack(node_t *head, int size, char **arr)
{
	int	i;

	i = 1;
	if (size == 2)
	{
		size = get_args(arr);
		i = 0;
	}
	while (i < size)
	{
		head = malloc(sizeof(node_t));
		if (head == NULL)
			return (0);
		head->content = ft_atoi(arr[i]);
		if (head->content >= INT_MAX || head->content <= INT_MIN
			|| ft_strlen(arr[i]) >= 11)
			return (ft_error());
		ft_lstnew(head);
		i++;
	}
	return (1);
}

void sort_two_nodes(node_t *node1) {
    if (node1 == NULL || node1->next == NULL) 
        return;

    node_t *node2 = node1->next;
    if (node1->content > node2->content) 
	{
        int temp = node1->content;
        node1->content = node2->content;
        node2->content = temp;
        ft_putendl_fd("sa", 1);
    }
}

