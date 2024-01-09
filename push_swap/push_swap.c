/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:00:33 by codespace         #+#    #+#             */
/*   Updated: 2024/01/09 17:45:53 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_lst_stack *i;
	t_lst_stack *j;

	i = NULL;
	j = NULL;
	if (argc == 0)
		return (0);
	else if (ft_strlen(argv[1]) >= 3 && argc == 1)
		argv = ft_split(argv[1], ' ');
	check_validity(*i, argc, argv);
}