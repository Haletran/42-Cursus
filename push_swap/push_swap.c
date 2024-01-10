/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:00:33 by codespace         #+#    #+#             */
/*   Updated: 2024/01/10 13:53:18 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	main(int argc, char **argv)
{
	node_t	*a;

	// t_lst_stack	*b;
	a = NULL;
	// b = NULL;
	if (argc == 1 || !ft_strchr(argv[1], ' '))
		return (ft_error());
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	if (verif_input(argc, argv))
		init_stack(a, argc, argv);
	else
		return (ft_error());
}