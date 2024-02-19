/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:09:03 by bapasqui          #+#    #+#             */
/*   Updated: 2024/02/19 14:28:18 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

int	main(int argc, char **argv)
{
	t_lst	**args;

	args = malloc(sizeof(t_lst));
	if (argc - 1 < 4)
		return (ft_error(1));
	if (!checker(argv))
		return (ft_error(2));
	*args = malloc(sizeof(t_lst));
	init_value(*args, argv);
	printf("%d", (*args)->nb_philo);
	return (0);
}
