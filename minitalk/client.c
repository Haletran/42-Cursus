/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:12:56 by codespace         #+#    #+#             */
/*   Updated: 2023/12/19 17:33:36 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
		usleep(1000);
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	pid;

	i = 0;
	j = 0;
	if (argc != 3)
	{
		printf("\033[1;31mError\033[0m : Invalid Usage\n");
		exit(1);
	}
	pid = atoi(argv[1]);
	while (argv[2][i])
		i++;
	while (i > j)
	{
		send_signal(pid, argv[2][j]);
		j++;
	}
	send_signal(pid, '\0');
	return (0);
}
