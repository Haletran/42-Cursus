/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:39:32 by bapasqui          #+#    #+#             */
/*   Updated: 2024/01/17 18:56:45 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_error(int choice)
{
	if (choice == 1)
	{
		ft_putendl_fd("\033[1m\033[31m[ Error ]\033[0m : File does not exist",
			2);
		return (0);
	}
	else if (choice == 2)
	{
		ft_putendl_fd("\033[1m\033[31m[ Error ]\033[0m : Too many or not enough arguments",
			2);
		ft_putendl_fd("Usage : ./so_long mapname.ber", 1);
		return (0);
	}
	else if (choice == 3)
	{
		ft_putendl_fd("\033[1m\033[31m[ Error ]\033[0m : Map Invalid", 2);
		return (0);
	}
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	c;
	int	d;

	c = 0;
	d = 0;
	if (to_find[0] == '\0' || to_find == 0)
		return (str);
	if (str == 0)
		return (0);
	while (str[c] != '\0')
	{
		while (str[c + d] == to_find[d])
		{
			d++;
			if (to_find[d] == '\0')
				return (&str[c]);
		}
			d = 0;
			c++;
	}
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	c;

	c = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[c] == s2[c] && s1[c] != '\0')
		c++;
	return ((unsigned char)s1[c] - (unsigned char)s2[c]);
}
