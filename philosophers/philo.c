/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:09:03 by bapasqui          #+#    #+#             */
/*   Updated: 2024/02/26 15:22:33 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

pthread_mutex_t	my_mutex;

int	main(int argc, char **argv)
{
	t_arg		**args;
	t_philo		**philo;
	int			i;

	i = 0;
	if (argc - 1 < 4)
		return (ft_error(1));
	if (!checker(argv))
		return (ft_error(2));
	args = malloc(sizeof(t_arg));
	philo = malloc(sizeof(t_philo));
	if (!args || !philo)
		return (ft_error(3));
	*args = calloc(sizeof(t_arg), argc - 1);
	*philo = calloc(sizeof(t_arg), 100);
	init_value(args, argv);
	if (!check_valid_time(*args))
		return(ft_error(2));
	print_args(*args);
	if (!create_thread(*args, *philo))
		return (0);

	printf("Join thread : %lu\n", (*philo)->thread_id[0]);
	pthread_join((*philo)->thread_id[0], NULL);
	printf("Join thread : %lu\n", (*philo)->thread_id[1]);
	pthread_join((*philo)->thread_id[1], NULL);
	//start_dinner(args, philo);
	return (0);
}
