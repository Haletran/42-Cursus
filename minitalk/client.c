/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:12:56 by codespace         #+#    #+#             */
/*   Updated: 2023/12/15 15:03:56 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

void	send_signal(int pid, unsigned char character)
{
	int				i;
	unsigned char	tmp;

	i = 8;
	tmp = character;
	while (i > 0)
	{
		i--;
		tmp = character >> i;
		if (tmp % 2)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(10000);
	}
}

int	main(int argc, char **argv)
{
	(void)argc;
	int i;
	int j;
	i = 0;
	j = 0;

	while (argv[2][i])
		i++;
	while (i > j)
	{
		send_signal(atoi(argv[1]), argv[2][j]);
		j++;
	}
	// write(1, "\n", 1);
	return (0);
}