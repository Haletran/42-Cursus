/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:13:56 by codespace         #+#    #+#             */
/*   Updated: 2023/12/14 20:51:02 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	get_pid(int process_id)
{
	process_id = getpid();
	return (process_id);
}
void	signalHandler(int signalNum)
{
	if (signalNum == SIGUSR1)
		printf("> Caught SIGUSR1 signal : %d\n", 1);
	else if (signalNum == SIGUSR2)
		printf("> Caught SIGUSR2 signal. %d\n", 0);
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
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		sleep(1);
	}
}