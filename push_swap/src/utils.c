/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptiste <baptiste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:26:30 by codespace         #+#    #+#             */
/*   Updated: 2024/02/01 22:06:17 by baptiste         ###   ########.fr       */
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

void	ft_free(t_lst **a, t_lst **b, int size, char **arr)
{
	struct s_lst	*tmp;
	int i;
	
	i = 0;

	if (a)
	{
		while (*a != NULL)
		{
			tmp = (*a)->next;
			free(*a);
			*a = tmp;
		}
		free(a);
	}
	if (b)
	{
		while (*b != NULL)
		{
			tmp = *b;
			*b = (*b)->next;
			free(tmp);
		}
		free(b);
	}
  	if (size == 2)
	{
	  while (arr[i])
		  free(arr[i++]);
		free(arr);
	}
}

void	print_list(char *string, t_lst *lst)
{
	ft_printf("%s\n", string);
	while (lst)
	{
		ft_printf("%d\n",lst->content);
		lst = lst->next;
	}
}
