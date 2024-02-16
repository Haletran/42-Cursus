/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptiste <baptiste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:21:51 by codespace         #+#    #+#             */
/*   Updated: 2024/02/16 13:04:30 by baptiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static long long	ft_atoi_test(const char *str, int flag)
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
		c++;
	}
	if ((e * oe) > INT_MAX || (e * oe) < INT_MIN)
		flag++;
	return (flag);
}

static int	check_list(int nb_args, int flag, char **src)
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
	if (!src)
		return (0);
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
int	ft_isdigit2(int c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	return (0);
}

int	check_input2(int nb_args, int flag, char **src)
{
	int	i;
	int	j;

	i = 1;
	if (flag == 1)
		i = 0;
	if (!src)
		return (0);
	while (i != nb_args)
	{
		j = 0;
		while (src[i][j])
			if (!ft_isdigit2(src[i][j++]))
				return (0);
		i++;
	}
	if (!src[0])
		return (0);
	return (1);
}


int	verif_input(int nb_args, int flag, char **src)
{
	if (!check_input(nb_args, flag, src))
		return (0);
	else if (!ft_isabove(src))
		return (0);
	else if (!check_list(nb_args, flag, src))
		return (0);
	else if (!(nb_args >= 2))
		return (-1);
	return (1);
}
