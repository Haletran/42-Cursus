/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptiste <baptiste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:03:50 by bapasqui          #+#    #+#             */
/*   Updated: 2024/01/21 21:50:54 by baptiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void    get_var(mlx_t *data)
{
    int height;
    int width;

    mlx_set_font_scale(data->mlx, data->win, "default", 20);
    data->nb_coin = 0;
	data->wall = mlx_png_file_to_image(data->mlx, "images/wall.png", &height, &width);
    data->ground = mlx_png_file_to_image(data->mlx, "images/black.png", &height, &width);
    data->exit = mlx_png_file_to_image(data->mlx, "images/exit.png", &height, &width);
    data->player = mlx_png_file_to_image(data->mlx, "images/player.png", &height, &width);
    data->coin = mlx_png_file_to_image(data->mlx, "images/coin.png", &height, &width);
}

void render_map(mlx_t *data)
{
    int x;
    int y;

    x = 0;
    y = 0;
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
            y++;
        }
        y = 0;
        x++;
    }
    
}
