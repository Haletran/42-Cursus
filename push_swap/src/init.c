/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:21:51 by codespace         #+#    #+#             */
/*   Updated: 2024/02/14 02:28:27 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static long long	ft_atoi_test(const char *str, int flag)
{
	int			c;
	int			d;
	long long	e;
	char		oe;

	c = 0;
	oe = 1;
	d = 0;
	e = 0;
	if ((str[c] == 43 || str[c] == 45) && !(str[c + 1] >= '0' && str[c \
			+ 1] <= '9'))
		flag++;
	while (str[c] == 32 || (str[c] >= 9 && str[c] <= 13))
		c++;
	if (str[c] == 43 || str[c] == 45)
		if (str[c++] == 45)
			oe = -1;
	while (str[c] >= '0' && str[c] <= '9')
	{
		e = e * 10 + str[c] - '0';
		c++;
	}
	if ((e * oe) > INT_MAX || (e * oe) < INT_MIN)
		flag++;
	return (flag);
}

static int	check_list(int nb_args, char **src)
{
	int	i;
	int	j;

	i = 1;
	if (!src)
		return (0);
	if (nb_args == 2)
	{
		nb_args = get_args(src);
		i = 0;
	}
	while (i < nb_args - 1)
	{
		j = i + 1;
		while (j < nb_args)
		{
			if (ft_strlen(src[i]) == 0)
				return (0);
			if (ft_atoi(src[i]) == ft_atoi(src[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_input(int nb_args, char **src)
{
	int	i;
	int	j;

	i = 1;
	if (!src)
		return (0);
	if (nb_args == 2)
	{
		nb_args = get_args(src);
		i = 0;
	}
	while (i != nb_args)
	{
		j = 0;
		while (src[i][j])
			if (!ft_isdigit(src[i][j++]))
				return (0);
		i++;
	}
	return (1);
}

static int	ft_isabove(char **src)
{
	int	flag;
	int	i;

	i = 0;
	flag = 0;
	while (src[i])
	{
		flag = ft_atoi_test(src[i], flag);
		i++;
	}
	if (flag > 0)
		return (0);
	return (1);
}

int	verif_input(int nb_args, char **src)
{
	if (check_input(nb_args, src) && check_list(nb_args, src) && ft_isabove(src)
		&& get_args(src) > 1)
		return (1);
	return (0);
}
