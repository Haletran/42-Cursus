/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:47:37 by baptiste          #+#    #+#             */
/*   Updated: 2024/01/23 19:09:17 by bapasqui         ###   ########.fr       */
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

void flood_fill(char **map_tmp, t_mlx *data, int x, int y, int rows, int cols) 
{
    if (x < 0 || x >= rows || y < 0 || y >= cols || map_tmp[x][y] == '1' || map_tmp[x][y] == 'S')
        return;
    if (map_tmp[x][y] == 'C')
        data->coin_count++;
    else if (map_tmp[x][y] == 'E')
        data->exit_count++;
    map_tmp[x][y] = 'S';
	flood_fill(map_tmp, data, x + 1, y, rows, cols);
    flood_fill(map_tmp, data, x - 1, y, rows, cols);
    flood_fill(map_tmp, data, x, y + 1, rows, cols);
    flood_fill(map_tmp, data, x, y - 1, rows, cols);
}

char **cpy(char **src, char ***dest)
{
    int i;
    int len;

    i = 0;
    len = 0;
    while (src[len] != NULL)
        len++;
    *dest = malloc((len + 1) * sizeof(char *));
	if (!dest)
		return (NULL);
    while (src[i] != NULL)
    {
        (*dest)[i] = strdup(src[i]);
        i++;
    }
    (*dest)[i] = NULL;
    return *dest;
}

