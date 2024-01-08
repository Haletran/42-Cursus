/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:21:51 by codespace         #+#    #+#             */
/*   Updated: 2024/01/08 17:28:59 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Parse input
// Check validity : not letters, not random things

#include "../includes/push_swap.h"

int	ft_atoi(const char *str)
{
	int		c;
	int		d;
	int		e;
	char	oe;

	c = 0;
	oe = 1;
	d = 0;
	e = 0;
	while (str[c] == 32 || (str[c] >= 9 && str[c] <= 13))
		c++;
	if (str[c] == 43 || str[c] == 45)
	{
		if (str[c] == 45)
			d++;
		c++;
	}
	while (str[c] >= '0' && str[c] <= '9')
	{
		e = e * 10 + str[c] - '0';
		c++;
	}
	if (d == 1)
		oe = -1;
	return (e * oe);
}
int	ft_isdigit(int i)
{
	if (i >= '0' && i <= '9')
		return (1);
	else
		return (0);
}
int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	validity;

	j = 0;
	validity = 0;
	i = 1;
	if (argc <= 2)
		return (1);
	while (i < argc)
	{
		while (argv[i][j])
		{
			if (ft_isdigit(ft_atoi(&argv[i][j])))
				validity++;
			j++;
		}
		if (validity == j)
			write(1, "VALID\n", 6);
		j = 0;
		validity = 0;
		i++;
	}
	return (0);
}
