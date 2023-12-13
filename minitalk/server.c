/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:13:56 by codespace         #+#    #+#             */
/*   Updated: 2023/12/13 17:07:50 by codespace        ###   ########.fr       */
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
		printf("> Caught SIGUSR1 signal : %d\n", signalNum);
	else if (signalNum == SIGUSR2)
		printf("> Caught SIGUSR2 signal. %d\n", signalNum);
}

int	main(void)
{
	int process_id;
	process_id = 0;
	printf("-----MINITALK-----\n");
	printf("PID : %d\n", get_pid(process_id));
	printf("-----MESSAGES-----\n\n");
	while (1)
	{
		signal(SIGUSR1, signalHandler);
		sleep(1);
	}
}