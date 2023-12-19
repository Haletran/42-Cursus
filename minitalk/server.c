/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:13:56 by codespace         #+#    #+#             */
/*   Updated: 2023/12/19 15:54:54 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	binary_to_ascii(const char *binary);

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}
int	get_pid(int process_id)
{
	process_id = getpid();
	return (process_id);
}
int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}
int	ft_putstr_fd(char *s, int fd)
{
	int	c;

	c = 0;
	if (!s)
		return (ft_putstr_fd("(null)", 1));
	while (s[c] != '\0')
	{
		ft_putchar_fd(s[c], fd);
		c++;
	}
	return (c);
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
	static char	*line = NULL;
	static int	len = 0;
	int			decimal;
	int			base;
	int			i;

	if (line == NULL)
	{
		line = malloc(len++);
		if (line == NULL)
			return ('\0');
	}
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
	if ((char)decimal == 0)
	{
		line[len] = '\0';
		ft_putstr_fd(line, 1);
		free(line);
		line = NULL;
		len = 0;
	}
	else
	{
		line[len] = (char)decimal;
		len++;
	}
	return ((char)decimal);
}

int	main(void)
{
	int					process_id;
	struct sigaction	sa;

	process_id = 0;
	// structure for sigaction
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
