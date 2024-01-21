/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptiste <baptiste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:03:50 by bapasqui          #+#    #+#             */
/*   Updated: 2024/01/21 16:26:49 by baptiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void    get_var(mlx_t *data)
{
    int height;
    int width;

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
            else if (data->map[x][y] == 'E')
                mlx_put_image_to_window(data->mlx, data->win, data->exit, y*32, x*32);
            y++;
        }
        y = 0;
        x++;
    }
    
}

void move_up(mlx_t *data)
{
    int tmp;
    tmp = data->player_x;
    if (data->map[data->player_x - 1][data->player_y] != '1')
    {
        mlx_put_image_to_window(data->mlx, data->win, data->player, data->player_y*32, (data->player_x - 1)*32);
        data->player_x--;
        mlx_put_image_to_window(data->mlx, data->win, data->ground, data->player_y*32, tmp*32);
        mlx_string_put(data->mlx, data->win, 10, 10, 0xFF0000FF, ft_itoa(data->nb_move++));   
    }
}

void move_down(mlx_t *data)
{
    int tmp;
    tmp = data->player_x;
    if (data->map[data->player_x + 1][data->player_y] != '1')
    {
        mlx_put_image_to_window(data->mlx, data->win, data->player, data->player_y*32, (data->player_x + 1)*32);
        data->player_x++;
        mlx_put_image_to_window(data->mlx, data->win, data->ground, data->player_y*32, tmp*32);
        mlx_string_put(data->mlx, data->win, 10, 10, 0xFF0000FF, ft_itoa(data->nb_move++)); 
    }
}

void move_right(mlx_t *data)
{
    int tmp;
    tmp = data->player_y;
    if (data->map[data->player_x][data->player_y + 1] != '1')
    {
        mlx_put_image_to_window(data->mlx, data->win, data->player, (data->player_y + 1)*32, data->player_x*32);
        data->player_y++;
        mlx_put_image_to_window(data->mlx, data->win, data->ground, tmp*32, data->player_x*32);
        mlx_string_put(data->mlx, data->win, 10, 10, 0xFF0000FF, ft_itoa(data->nb_move++)); 
    }
}

void move_left(mlx_t *data)
{
    int tmp;
    tmp = data->player_y;
    if (data->map[data->player_x][data->player_y - 1] != '1')
    {
        mlx_put_image_to_window(data->mlx, data->win, data->player, (data->player_y - 1)*32, data->player_x*32);
        data->player_y--;
        mlx_put_image_to_window(data->mlx, data->win, data->ground, tmp*32, data->player_x*32);
        mlx_string_put(data->mlx, data->win, 10, 10, 0xFF0000FF, ft_itoa(data->nb_move++)); 
    }
}
