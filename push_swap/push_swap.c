/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:00:33 by codespace         #+#    #+#             */
/*   Updated: 2024/02/01 12:23:00 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_lst	*a;
	//t_lst	*b;
	int count;

	count = 1;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (ft_error());
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		count--;
	}
	a = NULL;
	//b = NULL;
	if (verif_input(argc, argv))
	{
		a = init_stack(a, argc, argv, count);
		print_list(a);
/* 		if (argc - 1 <= 5 || get_args(argv) <= 5)
			sort_small_stack(a, b);
		else if (argc - 1 > 5 || get_args(argv) > 5)
			sort_big_stack(a, b); */
	}
	else
	{
		ft_free(a, argc, argv);
		return (ft_error());
	}
	ft_free(a, argc, argv);
}
