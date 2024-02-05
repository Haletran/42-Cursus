/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:00:33 by codespace         #+#    #+#             */
/*   Updated: 2024/02/05 16:28:03 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_lst	**a;
	t_lst	**b;
	int		count;
	int		size;

	count = 1;
	size = argc;
	if (argc == 2 && !argv[1][0])
		return (ft_error());
	if (argc == 2)
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
		if (argc - 1 <= 5 || get_args(argv) <= 5)
			a = sort_small_stack(a, b, size);
	}
	else
	{
		ft_free(a, b, argc, argv);
		if (argc == 1)
			return (0);
		return (ft_error());
	}
	ft_free(a, b, argc, argv);
}
