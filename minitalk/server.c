/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:13:56 by codespace         #+#    #+#             */
/*   Updated: 2023/12/20 20:31:30 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char	*line = NULL;

int	get_pid(int process_id)
{
	process_id = getpid();
	return (process_id);
}
void	print_line(char *line, char decimal)
{
	ft_putstr_fd(line, 1);
	if (decimal == 0)
		ft_putchar_fd('\n', 1);
}

char	*ft_join(char *src1, char src2)
{
	char	*result;
	int		len_src1;
	int		c;

	len_src1 = ft_strlen(src1);
	result = (char *)malloc(sizeof(*result) * (len_src1 + 2));
	if (result == NULL)
		return (NULL);
	c = 0;
	while (c < len_src1)
	{
		result[c] = src1[c];
		c++;
	}
	result[c++] = src2;
	result[c] = '\0'; 
	free(src1);
	return (result);
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
	if ((char)decimal == 0)
	{
		print_line(line, decimal);
		free(line);
		line = NULL;
	}
	line = ft_join(line, (char)decimal);
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
