/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:09:41 by bapasqui          #+#    #+#             */
/*   Updated: 2024/02/27 12:28:58 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_free_all(t_table **table)
{
    free((*table)->philos->id);
	free((*table)->philos->thread_id);
	free((*table)->philos);
	free(*table);
	*table = NULL;
    free(table);
}
