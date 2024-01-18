/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:03:50 by bapasqui          #+#    #+#             */
/*   Updated: 2024/01/18 20:01:21 by bapasqui         ###   ########.fr       */
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
	data->wall = mlx_png_file_to_image(data->mlx, "images/brick.png", &height, &width);
    data->ground = mlx_png_file_to_image(data->mlx, "images/sol.png", &height, &width);
    data->exit = mlx_png_file_to_image(data->mlx, "images/exit.png", &height, &width);
    data->player = mlx_png_file_to_image(data->mlx, "images/player2.png", &height, &width);
    data->coin = mlx_png_file_to_image(data->mlx, "images/coin2.png", &height, &width);
    
    while (data->map[x] != NULL)
    {
        while(data->map[x][y] != '\0')
        {
            if (data->map[x][y] == '1')
                mlx_put_image_to_window(data->mlx, data->win, data->wall, y*60, x*60);
            else if (data->map[x][y] == '0')
                mlx_put_image_to_window(data->mlx, data->win, data->ground, y*60, x*60);
            else if (data->map[x][y] == 'C')
                mlx_put_image_to_window(data->mlx, data->win, data->coin, y*60 , x*60 );
            else if (data->map[x][y] == 'P')
                mlx_put_image_to_window(data->mlx, data->win, data->player, data->player_y*60, data->player_x*60);
            else if (data->map[x][y] == 'E')
                mlx_put_image_to_window(data->mlx, data->win, data->exit, y*60, x*60);
            y++;
        }
        y = 0;
        x++;
    }
    
}

