/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:13:56 by codespace         #+#    #+#             */
/*   Updated: 2023/12/19 17:35:43 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	get_pid(int process_id)
{
	process_id = getpid();
	return (process_id);
}
void	print_char(char line)
{
	if (line == 0)
		ft_putchar_fd('\n', 1);
	ft_putchar_fd(line, 1);
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
void	binary_to_ascii(const char *binary)
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
	print_char((char)decimal);
}
int	main(void)
{
	int	process_id;

	process_id = 0;
	ft_putstr_fd("--] MINITALK [--\n", 1);
	printf("PID : %d\n\n", get_pid(process_id));
	ft_putstr_fd("--] Messages [--\n\n", 1);
	signal(SIGUSR1, signalHandler);
	signal(SIGUSR2, signalHandler);
	while (1)
		pause();
}
