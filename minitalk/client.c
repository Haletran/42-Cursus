/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:12:56 by codespace         #+#    #+#             */
/*   Updated: 2023/12/14 21:00:22 by codespace        ###   ########.fr       */
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
		usleep(42);
	}
}

char	binary_to_ascii(const char *binary)
{
	int	decimal;
	int	base;
	int	i;

	decimal = 0;
	base = 1;
	i = 7;
	while (i >= 0)
	{
		if (binary[i] == '1')
			decimal += base;
		base *= 2;
		i--;
	}
	return ((char)decimal);
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	char binary[] = "01001000"; // Example binary string
	char ascii = binary_to_ascii(binary);
	printf("ASCII character: %c\n", ascii);
	// send_signal(atoi(argv[1]), ascii);
	return (0);
}