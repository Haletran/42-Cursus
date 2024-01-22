/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:03:50 by bapasqui          #+#    #+#             */
/*   Updated: 2024/01/22 10:22:55 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	get_var(t_mlx *data)
{
	int	height;
	int	width;

	mlx_set_font_scale(data->mlx, data->win, "default", 20);
	data->nb_coin = 0;
	data->wall = mlx_png_file_to_image(data->mlx, "images/wall.png", &height,
			&width);
	data->ground = mlx_png_file_to_image(data->mlx, "images/black.png", &height,
			&width);
	data->exit = mlx_png_file_to_image(data->mlx, "images/exit.png", &height,
			&width);
	data->player = mlx_png_file_to_image(data->mlx, "images/player.png",
			&height, &width);
	data->coin = mlx_png_file_to_image(data->mlx, "images/coin.png", &height,
			&width);
}

void	render_map(t_mlx *data)
{
	data->x = 0;
	data->y = 0;
	while (data->map[data->x] != NULL)
	{
		while (data->map[data->x][data->y] != '\0')
		{
			if (data->map[data->x][data->y] == '1')
				mlx_put_image_to_window(data->mlx, data->win, data->wall,
					data->y * 32, data->x * 32);
			else if (data->map[data->x][data->y] == '0')
				mlx_put_image_to_window(data->mlx, data->win, data->ground,
					data->y * 32, data->x * 32);
			else if (data->map[data->x][data->y] == 'C')
				mlx_put_image_to_window(data->mlx, data->win, data->coin,
					data->y * 32, data->x * 32);
			else if (data->map[data->x][data->y] == 'P')
				mlx_put_image_to_window(data->mlx, data->win, data->player,
					data->player_y * 32, data->player_x * 32);
			data->y++;
		}
		data->y = 0;
		data->x++;
	}
}
