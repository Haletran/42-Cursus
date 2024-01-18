/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptiste <baptiste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:03:50 by bapasqui          #+#    #+#             */
/*   Updated: 2024/01/18 23:26:36 by baptiste         ###   ########.fr       */
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
	data->wall = mlx_png_file_to_image(data->mlx, "images/wall.png", &height, &width);
    data->ground = mlx_png_file_to_image(data->mlx, "images/black.png", &height, &width);
    data->exit = mlx_png_file_to_image(data->mlx, "images/exit.png", &height, &width);
    data->player = mlx_png_file_to_image(data->mlx, "images/player.png", &height, &width);
    data->coin = mlx_png_file_to_image(data->mlx, "images/coin.png", &height, &width);
    
    while (data->map[x] != NULL)
    {
        while(data->map[x][y] != '\0')
        {
            if (data->map[x][y] == '1')
                mlx_put_image_to_window(data->mlx, data->win, data->wall, y*32, x*32);
            else if (data->map[x][y] == '0')
                mlx_put_image_to_window(data->mlx, data->win, data->ground, y*32, x*32);
            else if (data->map[x][y] == 'C')
                mlx_put_image_to_window(data->mlx, data->win, data->coin, y*32 , x*32 );
            else if (data->map[x][y] == 'P')
                mlx_put_image_to_window(data->mlx, data->win, data->player, data->player_y*32, data->player_x*32);
            else if (data->map[x][y] == 'E')
                mlx_put_image_to_window(data->mlx, data->win, data->exit, y*32, x*32);
            y++;
        }
        y = 0;
        x++;
    }
    
}

void move_player(int keycode)
{
    mlx_t *data;
    int width;
    int height;

    data = malloc(sizeof(mlx_t));
    data = get_co(data);

    data->wall = mlx_png_file_to_image(data->mlx, "images/wall.png", &height, &width);
    data->ground = mlx_png_file_to_image(data->mlx, "images/black.png", &height, &width);
    data->exit = mlx_png_file_to_image(data->mlx, "images/exit.png", &height, &width);
    data->player = mlx_png_file_to_image(data->mlx, "images/player.png", &height, &width);
    data->coin = mlx_png_file_to_image(data->mlx, "images/coin.png", &height, &width);
    if (keycode == 26)
    {
        mlx_put_image_to_window(data->mlx, data->win, data->player, data->player_y*32, (data->player_x - 1)*32);
        mlx_put_image_to_window(data->mlx, data->win, data->player, data->player_y*32, data->player_x*32);    
    }
}



