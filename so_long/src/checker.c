/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:14:44 by codespace         #+#    #+#             */
/*   Updated: 2024/01/23 17:17:49 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	check_walls(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[0][y] != '\n')
		if (map[0][y++] != '1')
			return (0);
	y = 0;
	while (map[x + 1] != NULL)
		x++;
	while (y < x)
		if (map[y++][0] != '1')
			return (0);
	y = 0;
	while (map[x] != NULL && map[x][y] != '\0')
		if (map[x][y++] != '1')
			return (0);
	x = 0;
	while (map[x] != NULL && map[x][y - 1] != '\0')
		if (map[x++][y - 1] != '1')
			return (0);
	return (1);
}

static int	check_if_rectangle(char **map)
{
	int	x;
	int	tmp;
	int	y;

	y = 0;
	x = 0;
	while (map[x] != NULL)
		x++;
	tmp = x;
	x = 0;
	while (x < tmp)
	{
		while (map[x][y])
			y++;
		if (tmp == y)
			return (0);
		y = 0;
		x++;
	}
	return (1);
}

static int	check_p(char **map)
{
	int	x;
	int	value;
	int	value2;
	int	y;

	x = 0;
	value = 0;
	value2 = 0;
	while (map[x] != NULL)
	{
		y = 0;
		while (map[x][y] != '\0')
		{
			if (map[x][y] == 'P')
				value++;
			if (map[x][y] == 'E')
				value2++;
			y++;
		}
		x++;
	}
	if (value == 1 && value2 == 1)
		return (1);
	return (0);
}

static int	check_collectibles(char **map)
{
	int	x;
	int	value;
	int	y;

	x = 0;
	value = 0;
	
	while (map[x] != NULL)
	{
		y = 0;
		while (map[x][y] != '\n' && map[x][y] != '\0')
		{
			if (map[x][y] == 'C')
				value++;
			if (isnotinset(map[x][y]))
				return (0);
			y++;
		}
		x++;
	}
	if (value == 0)
		return (0);
	return (1);
}
char	*ft_strejoin(char *src1, char *src2)
{
	char	*result;
	int		c;
	int		d;
	int		len;

	c = 0;
	d = 0;
	if (!src1 && !src2)
		return (NULL);
	len = (ft_strlen(src1) + ft_strlen(src2) + 1);
	result = malloc(sizeof(*result) * len);
	if (result == NULL)
		return (NULL);
	while (c < (int)ft_strlen(src1))
	{
		result[c] = src1[c];
		c++;
	}
	while (c < (int)(ft_strlen(src1) + ft_strlen(src2)))
		result[c++] = src2[d++];
	result[c] = '\0';
	free(src1);
	return (result);
}
char	*ft_stredup(const char *src)
{
	int		s;
	int		len;
	char	*dest;

	s = 0;
	len = ft_strlen(src);
	dest = malloc(sizeof(char) * (len + 1));
	if (dest == 0)
		return (0);
	while (src[s] != '\0')
	{
		dest[s] = src[s];
		s++;
	}
	dest[s] = '\0';
	return (dest);
}

int	global_checker(t_mlx *data)
{
	data->map = initialize_map(data);
	if (data->map == NULL)
		return (0);
	if (!check_if_rectangle(data->map))
		return (0);
	if (!check_collectibles(data->map))
		return (0);
	if (!check_walls(data->map))
		return (0);
	if (!check_p(data->map))
		return (0);
	data = get_co(data);
	data->exit_count = 0;
	data->coin_count = 0;
	for (int i = 0; i < data->width; i++)
		data->map_tmp[i] = ft_stredup(data->map[i]);
	flood_fill(data->map_tmp, data, data->player_x, data->player_y, data->width, data->height);
	if (data->exit_count == 0 || data->coin_count == 0)
		return (0);
	for(int i = 0; i < 12; i++)
		ft_printf("%s", data->map[i]);
	return (1);
}
