/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:39:32 by bapasqui          #+#    #+#             */
/*   Updated: 2024/01/16 15:41:48 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_error(int choice)
{
    if (choice == 1)
    {
	    ft_putendl_fd("\033[1m\033[31m[ Error ]\033[0m : File does not exist", 2);
        return (0);
    }
    else if (choice == 2)
    {
        ft_putendl_fd("\033[1m\033[31m[ Error ]\033[0m : Too many or not enough arguments", 2);
        ft_putendl_fd("Usage : ./so_long mapname.ber", 1);
        return (0);
    }
    else if (choice == 3)
    {
        ft_putendl_fd("\033[1m\033[31m[ Error ]\033[0m : Map Invalid", 2);
        return (0);
    }
    return (1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	c;

	c = 0;
	while (s1[c] == s2[c] && (s1[c] != '\0' && s2[c] != '\0'))
		c++;
	return (s1[c] - s2[c]);
}
