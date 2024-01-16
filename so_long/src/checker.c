/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:14:44 by codespace         #+#    #+#             */
/*   Updated: 2024/01/16 16:28:55 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int check_walls(char **map)
{
    int i = 0;
    int j = 0;

    while (map[0][j])
    {
        if (ft_strcmp(&map[i][j], "1") == 0)
            return 0;
        j++;
    }

    i = 0;
    j = (int)ft_strlen(map[0]);
    while (map[i] != NULL)
    {
        if (map[i][0] != '1')
            return 0;
        i++;
    }
    i = 0;
    while (map[i][j])
    {
        if (ft_strcmp(&map[i][j], "1") == 0)
            return 0;
        i++;
    }
    i = (int)ft_strlen(*map);
    ft_printf()
    while(map[i][j] != '\n')
    {
        if(map[i][j] != '1')
            return (0);
        j++;
    }

    return 1;
}

static int	check_if_rectangle(char **map)
{
	int	i;
	int	tmp;
	int	j;

	j = 0;
	i = 0;
	while (map[i] != NULL)
		i++;
	tmp = i;
	i = 0;
	while (i < tmp)
	{
		while (map[i][j])
			j++;
		if (tmp == j)
			return (0);
		j = 0;
		i++;
	}
	return (1);
}

int	global_checker(int fd)
{
	char	**map;

	map = stock_map(fd);
	if (check_if_rectangle(map) && check_walls(map))
        return (1);
	return (0);
}
