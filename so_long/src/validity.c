/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:47:37 by baptiste          #+#    #+#             */
/*   Updated: 2024/01/22 17:37:14 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// flood fill
t_mlx	*get_mapwh(t_mlx *data)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (data->map[x] != NULL)
		x++;
	data->width = x;
	x = 0;
	while (data->map[x][y] != '\0' && data->map[x][y] != '\n')
		y++;
	data->height = y;
	return (data);
}

t_mlx	*get_co(t_mlx *data)
{
	data->x = 0;
	data->y = 0;
	get_mapwh(data);
	while (data->map[data->x] != NULL)
	{
		while (data->map[data->x][data->y] != '\0')
		{
			if (data->map[data->x][data->y] == 'E')
			{
				data->end_x = data->x;
				data->end_y = data->y;
			}
			if (data->map[data->x][data->y] == 'P')
			{
				data->player_x = data->x;
				data->player_y = data->y;
			}
			if (data->map[data->x][data->y] == 'C')
				data->coins++;
			data->y++;
		}
		data->y = 0;
		data->x++;
	}
	return (data);
}

/* void flood_fill(t_mlx *data, int x, int y) 
{
	data->map_tmp = data->map;
	if (data->map_tmp[x][y] == '1')
		return (0);
    if (data->map_tmp[x][y] != 'S')
        return;
    map[x][y] = 'S';
    flood_fill(data->map_tmp, x + 1, y, target, 'S');
    flood_fill(data->map_tmp, x - 1, y, target, 'S');
    flood_fill(data->map_tmp, x, y + 1, target, replacement);
    flood_fill(data->map_tmp, x, y - 1, target, replacement);
} */

int	store(t_mlx *data)
{
	data = get_co(data);
	if (!data->map)
	{
		ft_free(data);
		return (0);
	}
	return (1);
}
