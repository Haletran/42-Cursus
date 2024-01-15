/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:00:33 by codespace         #+#    #+#             */
/*   Updated: 2024/01/15 12:38:23 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	main(int argc, char **argv)
{
	node_t	*a;
	node_t	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (ft_error());
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	if (verif_input(argc, argv))
	{
		init_stack(&a, argc, argv);
		if (argc == 3 || get_args(argv) == 2)
			sa(&a);
		// Why I'm doing this instead of just one function
		else if (argc == 4 || get_args(argv) == 3)
			pa(&a, &b);
		/* 		else if (argc == 6 || get_args(argv) == 5)
					sort_two_nodes(a);
				else
					sort_multiples_nodes(a); */
		freeList(a);
	}
	else
		// TODO: - fix this shitty error if input already sorted
		return (ft_error());
}
