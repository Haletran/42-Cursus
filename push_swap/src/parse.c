/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 20:47:27 by codespace         #+#    #+#             */
/*   Updated: 2024/01/31 16:41:45 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// TODO: why the fuck is the arr is reversed in the new_node
// TODO: need to check another if the input is sorted in case of a split WTF (ex: "1 2" 1)
int	init_stack(t_lst **head, int size, char **arr)
{
	int		i;
	t_lst	*new_node;
	i = 1;
	if (size == 2)
	{
		size = get_args(arr);
		i = 0;
	}
	*head = NULL;
	while (i < size)
	{
		new_node = malloc(sizeof(t_lst));
		if (new_node == NULL)
			return (0);
		new_node->content = ft_atoi(arr[i]);
		if (new_node->content >= INT_MAX || new_node->content <= INT_MIN
			|| ft_strlen(arr[i]) >= 11)
		{
			free(new_node);
			return (ft_error());
		}
		ft_lstadd_back(new_node, new_node->content);
		//ft_printf("%d\n", new_node->content);
		i++;
	}
	return (1);
}


