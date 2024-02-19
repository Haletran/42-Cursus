/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:00:33 by codespace         #+#    #+#             */
/*   Updated: 2024/02/19 15:51:40 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	*sort_stacks(int size, char **arr, int flag)
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
	size = ft_lst_size(*a);
	choose_sort(a, b, size);
	ft_free(a, b, flag, arr);
	return (0);
}

int	main(int argc, char **argv)
{
	int	size;
	int	flag;

	size = argc;
	flag = 0;
	if (argc == 2 && !argv[1][0])
		return (ft_error());
	else if (size == 2)
	{
		argv = ft_split(argv[1], ' ');
		flag = 1;
		size = get_args(argv);
	}
	if (global_check(size, flag, argv) == -1)
	{
		ft_free(NULL, NULL, flag, argv);
		return (0);
	}
	else if (global_check(size, flag, argv) == 0)
	{
		ft_free(NULL, NULL, flag, argv);
		return (ft_error());
	}
	sort_stacks(size, argv, flag);
	return (1);
}
