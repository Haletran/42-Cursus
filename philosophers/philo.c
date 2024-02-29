/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:09:03 by bapasqui          #+#    #+#             */
/*   Updated: 2024/02/29 22:48:04 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

int	main(int argc, char **argv)
{
	t_table	**table;
	int		i;

	i = 0;
	if (argc - 1 < 4)
		return (ft_error(1));
	if (!checker(argv))
		return (ft_error(2));
	table = malloc(sizeof(t_table));
	*table = malloc(sizeof(t_table));
	init_value(table, argv);
	if (!check_valid_time(*table))
		return (ft_error(2));
	print_table(*table);
	create_thread(table);
	start_dinner(table);
	ft_free_all(table);
	return (0);
}
