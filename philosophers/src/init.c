/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:00:02 by bapasqui          #+#    #+#             */
/*   Updated: 2024/02/19 13:21:00 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_lst	init_value(t_lst *args, char **arr)
{
    args->nb_philo = ft_atoi(arr[1]);
	args->time_to_die = ft_atoi(arr[2]);
	args->time_to_eat = ft_atoi(arr[3]);
	args->time_to_sleep = ft_atoi(arr[4]);
	if(arr[5])
		args->must_eat = ft_atoi(arr[5]);
    return (*args);
}