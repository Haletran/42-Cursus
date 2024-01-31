/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:26:30 by codespace         #+#    #+#             */
/*   Updated: 2024/01/31 19:05:00 by bapasqui         ###   ########.fr       */
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

int	ft_strcmp(char *s1, char *s2)
{
	int	c;

	c = 0;
	while (s1[c] == s2[c] && (s1[c] != '\0' && s2[c] != '\0'))
		c++;
	return (s1[c] - s2[c]);
}

int	ft_error(void)
{
	ft_putendl_fd("Error", 2);
	return (0);
}

void	freeList(t_lst *a)
{
	struct s_lst	*tmp;

/* 	if (!a)
		while(a)
			a = a->prev; */
		
	while (a != NULL)
	{
		tmp = a;
		a = a->next;
		free(tmp);
	}
}
/*
		if (new_node->content > INT_MAX || new_node->content < INT_MIN
			|| ft_strlen(arr[i]) >= 11)
		{
			free(new_node);
			ft_error();
			return (0);
		} */
