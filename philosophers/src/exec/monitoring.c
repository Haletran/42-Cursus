/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptiste <baptiste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:16:53 by bapasqui          #+#    #+#             */
/*   Updated: 2024/04/26 00:01:42 by baptiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	check_death(t_philo *philos)
{
	pthread_mutex_lock(&philos->infos->print_mutex);
	if ((actual_time() - philos->infos->start_time)
		- philos->last_meal > philos->infos->t_die)
	{
		if (philos->infos->end_of_simulation != 1)
		{
			philos->status = DEAD;
			philos->infos->end_of_simulation = 1;
			print_status(philos);
			pthread_mutex_unlock(&philos->infos->print_mutex);
			return (END_OF_SIMULATION);
		}
	}
	pthread_mutex_unlock(&philos->infos->print_mutex);
	return (SUCCESS);
}

int	check_fullness(t_philo *philos)
{
	int i;

	i = 0;
	pthread_mutex_lock(&philos->infos->print_mutex);
	while (1)
	{
		if (philos->is_full == true)
			i++;
		if (philos->last == 1)
			break;
		philos = philos->next;
	}
	if (i == philos->infos->nb_philo)
	{
		philos->infos->end_of_simulation = 1;
		pthread_mutex_unlock(&philos->infos->print_mutex);
		return (END_OF_SIMULATION);
	}
	pthread_mutex_unlock(&philos->infos->print_mutex);
	return (SUCCESS);
}

int	check_end_simulation(t_philo *philos)
{
	pthread_mutex_lock(&philos->infos->print_mutex);
	if (philos->infos->end_of_simulation == 1)
	{
		pthread_mutex_unlock(&philos->infos->print_mutex);
		return (END_OF_SIMULATION);
	}
	pthread_mutex_unlock(&philos->infos->print_mutex);
	return (SUCCESS);
}
