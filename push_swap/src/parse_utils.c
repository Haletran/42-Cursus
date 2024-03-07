/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:21:51 by codespace         #+#    #+#             */
/*   Updated: 2024/03/06 18:03:29 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_is_digit(int c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	return (0);
}

long long	ft_atoi_max(const char *str, int flag)
{
	int			c;
	long long	e;
	char		oe;

	c = 0;
	oe = 1;
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
		if ((e * oe) > INT_MAX || (e * oe) < INT_MIN)
			flag++;
		c++;
	}
	return (flag);
}

int	check_list(int nb_args, int flag, char **src)
{
	int	i;
	int	j;

	i = 1;
	if (flag == 1)
		i = 0;
	if (!src)
		return (0);
	while (i < nb_args)
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

int	check_input(int nb_args, int flag, char **src)
{
	int	i;
	int	j;

	i = 1;
	if (flag == 1)
		i = 0;
	while (i != nb_args)
	{
		j = 0;
		while (src[i][j])
		{
			if (!ft_isdigit(src[i][j]))
				return (0);
			if (ft_is_digit(src[i][j]) && (src[i][j + 1] == 32
					|| ft_is_digit(src[i][j + 1]) || src[i][j + 1] == '\0'))
				j++;
			else if ((src[i][j] == '+' || src[i][j] == '-')
				&& !ft_is_digit(src[i][j + 1]))
				return (0);
			else
				j++;
		}
		i++;
	}
	return (1);
}

int	ft_isabove(char **src)
{
	int	flag;
	int	i;

	i = 0;
	flag = 0;
	while (src[i])
	{
		flag = ft_atoi_max(src[i], flag);
		i++;
	}
	if (flag > 0)
		return (0);
	return (1);
}
