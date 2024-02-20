/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:09:03 by bapasqui          #+#    #+#             */
/*   Updated: 2024/02/20 17:34:50 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

pthread_mutex_t	my_mutex;
int j;

void	*do_process(void *param)
{
	int	i;

	(void)param;
	pthread_mutex_lock(&my_mutex);
	i = 0;
	j++;
	while (i < 5)
	{
		printf("%d", j);
		i++;
	}
	printf("...Done\n");
	pthread_mutex_unlock(&my_mutex);
	pthread_exit(NULL);
}

int	main(int argc, char **argv)
{
	t_arg		*args;
	t_philo		*philo;
	int			i;
	pthread_t	p1;

	i = 0;
	if (argc - 1 < 4)
		return (ft_error(1));
	if (!checker(argv))
		return (ft_error(2));
	args = calloc(sizeof(t_arg), 100);
	philo = calloc(sizeof(t_philo), 100);
	if (!args || !philo)
	{
		free(args);
		free(philo);
		return (ft_error(3));
	}
	init_value(args, argv);
	pthread_mutex_init(&my_mutex, NULL);
	pthread_create(&(*philo).philo_id, NULL, do_process, NULL);
	pthread_create(&p1, NULL, do_process, NULL);
	pthread_join((*philo).philo_id, NULL);
	pthread_join(p1, NULL);
	return (0);
}
