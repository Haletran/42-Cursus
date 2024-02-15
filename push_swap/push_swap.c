/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptiste <baptiste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:00:33 by codespace         #+#    #+#             */
/*   Updated: 2024/02/15 23:29:06 by baptiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	*execution(int size, char **arr, int flag)
{
	t_lst	**a;
	t_lst	**b;

	a = ft_calloc(sizeof(t_lst *), size);
	b = ft_calloc(sizeof(t_lst *), size);
	*a = init_stack(*a, size, arr, flag);
	*b = NULL;
	if (is_sorted_list(a))
	{
		ft_free(a, b, flag, arr);
		return (0);
	}
	choose_sort(a, b, size, flag);
	ft_free(a, b, flag, arr);
	return (0);
}

int main(int argc, char **argv)
{
	int size;
	int flag;

	size = argc;
	flag = 0;
	if(argc == 2 && !argv[1][0])
		return (ft_error());
	else if (size == 2)
	{
		argv = ft_split(argv[1], ' ');
		flag = 1;
	}
	if (flag == 1)
		size = get_args(argv);
	if (verif_input(size, flag, argv))
		execution(size, argv, flag);
	else
	{
		ft_free(NULL, NULL, flag, argv);
		if (argc == 1)
			return (0);
		return (ft_error());
	}
	return (1);
}
