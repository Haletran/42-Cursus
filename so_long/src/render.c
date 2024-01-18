/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:03:50 by bapasqui          #+#    #+#             */
/*   Updated: 2024/01/18 17:02:54 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void render_map(mlx_t *data)
{
    int x;
    int width;
    int height;
    int y;

    x = 0;
    y = 0;
	data->wall = mlx_png_file_to_image(data->mlx, "images/brick.png", &width, &height);
    data->ground = mlx_png_file_to_image(data->mlx, "images/dirt.png", &width, &height);
    data->exit = mlx_png_file_to_image(data->mlx, "images/exit.png", &width, &height);
    data->player = mlx_png_file_to_image(data->mlx, "images/player.png", &width, &height);
    data->coin = mlx_png_file_to_image(data->mlx, "images/coin.png", &width, &height);
    while (data->map[x] != NULL)
    {
        while(data->map[x][y] != '\0')
        {
            if (data->map[x][y] == '1')
                mlx_put_image_to_window(data->mlx, data->win, data->wall, x + 10, y + 10);
            else if (data->map[x][y] == '0')
                mlx_put_image_to_window(data->mlx, data->win, data->wall, x + 10, y + 10);
            else if (data->map[x][y] == 'C')
                mlx_put_image_to_window(data->mlx, data->win, data->coin, x + 10, y + 10);
            else if (data->map[x][y] == 'P')
                mlx_put_image_to_window(data->mlx, data->win, data->player, data->player_x + 10, data->player_y + 10);
            else if (data->map[x][y] == 'E')
                mlx_put_image_to_window(data->mlx, data->win, data->exit, x + 10, y + 10);
            y++;
        }
        y = 0;
        x++;
    }
    
}

