/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:13:56 by codespace         #+#    #+#             */
/*   Updated: 2023/12/18 18:26:27 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	binary_to_ascii(const char *binary);

int	get_pid(int process_id)
{
	process_id = getpid();
	return (process_id);
}
void	signalHandler(int signalNum)
{
	static char	*character;
	static int	i = 0;

	if (character == NULL)
	{
		character = malloc(8);
		if (character == NULL)
			return ;
	}
	if (i < 8)
	{
		if (signalNum == SIGUSR1)
			character[i] = '1';
		else if (signalNum == SIGUSR2)
			character[i] = '0';
			
		i++;
		if (i == 8)
		{
			binary_to_ascii(character);
			free(character);
			character = NULL;
			i = 0;
		}
	}
}

char	binary_to_ascii(const char *binary)
{
	int				decimal;
	int				base;
	int				i;

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
	write(1, &decimal, 1);
	return ((char)decimal);
}

int	main(void)
{
	int process_id;
	process_id = 0;

	// structure for sigaction
	struct sigaction sa;
	sigemptyset(&sa.sa_mask);
	sa.sa_handler = &signalHandler;
	sa.sa_flags = SA_SIGINFO;

	// Get process ID and print it
	printf("-----MINITALK-----\n");
	printf("PID : %d\n", get_pid(process_id));
	printf("-----MESSAGES-----\n\n");
	
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
}
