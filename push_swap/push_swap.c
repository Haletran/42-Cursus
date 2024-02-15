/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:00:33 by codespace         #+#    #+#             */
/*   Updated: 2024/02/15 15:20:38 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

/* print_list("A\n", *a);
print_list("B\n", *b); */

void	*execution(int size, int count, char **arr, int argc)
{
	t_lst	**a;
	t_lst	**b;

	a = ft_calloc(sizeof(t_lst *), size + 1);
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
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		count--;
		size = get_args(argv);
	}
	if (!verif_input(argc, argv))
	{
		ft_free(NULL, NULL, argc, argv);
		if (argc == 1)
			return (0);
		return (ft_error());
	}
	execution(size, count, argv, argc);
	return (1);
}
