/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:14:44 by bapasqui          #+#    #+#             */
/*   Updated: 2024/02/27 14:55:13 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*start_dinner(t_table **table)
{
	int	i;

	i = 0;
	while (i < (*table)->nb_philo + 1)
	{
		pthread_join((*table)->philos->thread_id[i], NULL);
		i++;
	}
	return (NULL);
}
