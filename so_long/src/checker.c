/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:14:44 by codespace         #+#    #+#             */
/*   Updated: 2024/01/17 13:56:38 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	check_walls(char **map)
{
	int	i;
	int	tmp;
	int	j;

	i = 0;
	tmp = 0;
	j = 0;
	while (map[0][j])
	{
		if (ft_strcmp(&map[i][j++], "1") == 0)
			return (0);
	}
	i = 0;
	j = (int)ft_strlen(map[0]);
	while (map[i] != NULL)
	{
		if (map[i++][0] != '1')
			return (0);
	}
	tmp = i - 1;
	i = 0;
	while (map[i][j])
	{
		if (ft_strcmp(&map[i++][j], "1") == 0)
			return (0);
	}
	j = 0;
    // Bug car nl at end of file
	while (map[tmp][j] != '\0')
	{
		if (map[tmp][j++] != '1')
			return (0);
	}
	return (1);
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

static int	check_p(char **map)
{
	int	i;
	int	value;
	int	value2;
	int	j;

	i = 0;
	value = 0;
	value2 = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'P')
				value++;
			if (map[i][j] == 'E')
				value2++;
			j++;
		}
		i++;
	}
	if (value == 1 || value2 == 1)
		return (1);
	return (0);
}

static int check_collectibles(char **map)
{
    int	i;
	int	value;
	int	j;

	i = 0;
	value = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'C')
				value++;
			j++;
		}
		i++;
	}
	if (value == 0)
		return (0);
	return (1);
}

int	global_checker(int fd)
{
	mlx_t *data = malloc(sizeof(mlx_t));

	data->map = initialize_mlx(fd);
	if (check_if_rectangle(data->map) && check_walls(data->map) && check_p(data->map) && check_collectibles(data->map))
		return (1);
	return (0);
}
