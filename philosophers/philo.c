/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:09:03 by bapasqui          #+#    #+#             */
/*   Updated: 2024/02/26 19:47:13 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

int	main(int argc, char **argv)
{
	t_table **table;
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
	printf("Join thread : %ld id : %d\n", (*table)->philos->thread_id[0], (*table)->philos->id[0]);
	pthread_join((*table)->philos->thread_id[0], NULL);
	//start_dinner(table);
	return (0);
}
