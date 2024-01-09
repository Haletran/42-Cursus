/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:21:51 by codespace         #+#    #+#             */
/*   Updated: 2024/01/09 16:02:24 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_isdigit(int i)
{
	if ((i >= '0' && i <= '9') || (i == 43 || i == 45 || i == 32))
		return (1);
	else
		return (0);
}
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
	if (!str)
		return (0);
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
int	check_validity(int nb_args, char **src)
{
	int	i;
	int	j;
	int	a;

	a = 0;
	i = 1;
	while (i < nb_args)
	{
		j = 1;
		while (j < nb_args)
		{
			if (ft_atoi(src[i]) == ft_atoi(src[j]))
				a++;
			j++;
		}
		i++;
	}
	if (a > 0)
		return (0);
	return (1);
}

int	check_input(int nb_args, char **src)
{
	int	i;
	int	cool;
	int	j;
	int	validity;

	cool = 0;
	validity = 0;
	i = 1;
	if (nb_args <= 1)
		return (0);
	while (i < nb_args)
	{
		j = 0;
		while (src[i][j])
			validity += ft_isdigit(src[i][j++]);
		if (validity == j)
			cool++;
		validity = 0;
		i++;
	}
	if (cool == nb_args - 1)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	if (check_input(argc, argv))
	{
		if (check_validity(argc, argv) == 1)
			write(1, "VALID\n", 6);
		else
			write(1, "NOT VALID\n", 10);
	}
	else
		write(1, "NOT VALID\n", 10);
	return (0);
}