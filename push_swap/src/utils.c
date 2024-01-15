/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:26:30 by codespace         #+#    #+#             */
/*   Updated: 2024/01/15 12:24:44 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_args(char **arr)
{
	int	count;

	count = 0;
	while (*arr)
	{
		count++;
		arr++;
	}
	return (count);
}

int	ft_error(void)
{
	ft_putendl_fd("Error", 2);
	return (0);
}
int	ft_list_size(t_list *begin_list)
{
	int	size;

	size = 0;
	while (begin_list != NULL)
	{
		size++;
		begin_list = begin_list->next;
	}
	return (size);
}


void	freeList(struct node *head)
{
	struct node	*tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
