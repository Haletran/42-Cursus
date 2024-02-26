/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:00:02 by bapasqui          #+#    #+#             */
/*   Updated: 2024/02/26 15:20:20 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void init_value(t_arg **args, char **arr)
{
    (*args)->nb_philo = ft_atoi(arr[1]);
	(*args)->time_to_die = ft_atoi(arr[2]);
	(*args)->time_to_eat = ft_atoi(arr[3]);
	(*args)->time_to_sleep = ft_atoi(arr[4]);
	if(arr[5])
		(*args)->must_eat = ft_atoi(arr[5]);
}

int check_valid_time(t_arg (*args))
{
	if (args->time_to_die < 60)
		return (0);
	else if (args->time_to_eat < 60)
		return (0);
	else if (args->time_to_sleep < 60)
		return (0);
	else if (args->nb_philo > 200 || args->nb_philo == 0)
		return (0);
	return (1);
}

static void *runtime()
{
    pthread_t tid = pthread_self();
    printf("PHILO created with id: %lu\n", (unsigned long)tid);
    return NULL;
}

int create_thread(t_arg *args, t_philo *philo)
{
    int i;
    int check;

    i = 0;
    check = 0;
	philo->thread_id = malloc(100);
    while (i < args->nb_philo + 1)
    {
        check = pthread_create(&philo->thread_id[i], NULL, runtime, NULL);
        if (check)
        {
            printf("ERROR CREATING THREAD");
            return 0;
        }
        usleep(50);
        i++;
    }
    printf("-> %d threads created\n", i);
    return 1;
}










