/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:00:33 by codespace         #+#    #+#             */
/*   Updated: 2024/02/15 19:39:50 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	*execution(int size, int count, char **arr, int argc)
{
	t_lst	**a;
	t_lst	**b;

	a = ft_calloc(sizeof(t_lst *), size);
	b = ft_calloc(sizeof(t_lst *), size);
	*a = init_stack(*a, size, arr, count);
	*b = NULL;
	if (is_sorted_list(a))
	{
		ft_free(a, b, argc, arr);
		return (0);
	}
	if (count == 0)
		size += 1;
	choose_sort(a, b, size);
	ft_free(a, b, argc, arr);
	return (0);
}

int	main(int argc, char **argv)
{
	int	count;
	int	size;

	count = 1;
	size = argc;
	if (argc == 2 && !argv[1][0])
		return (ft_error());
	if (size == 2)
	{
		argv = ft_split(argv[1], ' ');
		count--;
		size = get_args(argv);
	}
	if (verif_input(argc, argv) && get_args(argv) > 1)
		execution(size, count, argv, argc);
	else
	{
		ft_free(NULL, NULL, argc, argv);
		if (argc == 1)
			return (0);
		return (ft_error());
	}
	return (1);
}
