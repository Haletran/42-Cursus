/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptiste <baptiste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:00:33 by codespace         #+#    #+#             */
/*   Updated: 2024/02/01 22:43:22 by baptiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_lst	**a;
	t_lst	**b;
	int count;
	int size;

	count = 1;
	size = argc;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (ft_error());
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		count--;
		size = get_args(argv);
	}
	a = ft_calloc(sizeof(t_lst *), size);
	b = ft_calloc(sizeof(t_lst *), size);
	if (verif_input(argc, argv)) 
	{
		*a = init_stack(*a, size, argv, count);
		*b = init_stack(*b, size, argv, count);
		//*a = ra(*a);
		print_list("A\n_", *a);
		print_list("\nB\n_", *b);
/* 		if (argc - 1 <= 5 || get_args(argv) <= 5)
			sort_small_stack(a, b); */
/* 		else if (argc - 1 > 5 || get_args(argv) > 5)
			sort_big_stack(a, b); */
	}
	else
	{
		ft_free(a, b, argc, argv);
		return (ft_error());
	}
	ft_free(a, b, argc, argv);
}
