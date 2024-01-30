/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:00:33 by codespace         #+#    #+#             */
/*   Updated: 2024/01/30 16:20:05 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_lst	*a;

	t_lst	*b;
	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (ft_error());
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	if (verif_input(argc, argv))
	{
		init_stack(&a, argc, argv);
		if (argc - 1 <= 5 || get_args(argv) <= 5)
			sort_small_stack(a, b);
		else if (argc - 1 > 5 || get_args(argv) > 5)
			sort_big_stack(a, b);
	}
	else
	// TODO: - fix this shitty error if input already sorted
		return (ft_error());
}
