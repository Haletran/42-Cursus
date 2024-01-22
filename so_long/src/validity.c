/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:47:37 by baptiste          #+#    #+#             */
/*   Updated: 2024/01/22 10:03:26 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// flood fill
mlx_t	*get_mapwh(mlx_t *data)
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

mlx_t	*get_co(mlx_t *data)
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

int	flood_fill(mlx_t *data)
{
	data = get_co(data);
	return (1);
}
