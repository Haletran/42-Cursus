/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptiste <baptiste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 21:51:06 by baptiste          #+#    #+#             */
/*   Updated: 2024/01/21 22:07:30 by baptiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


void move_up(mlx_t *data)
{
    int tmp;
    tmp = data->player_x;
    if (data->map[data->player_x - 1][data->player_y] != '1')
    {
        if (data->map[data->player_x - 1][data->player_y] == 'C')
            data->nb_coin++;
        if (data->nb_coin == data->coins)
            mlx_put_image_to_window(data->mlx, data->win, data->exit, data->end_y*32, data->end_x*32);
        mlx_put_image_to_window(data->mlx, data->win, data->player, data->player_y*32, (data->player_x - 1)*32);
        data->player_x--;
        data->map[tmp][data->player_y] = '0';
        mlx_put_image_to_window(data->mlx, data->win, data->ground, data->player_y*32, tmp*32);
        if (data->nb_coin == data->coins && data->map[data->player_x][data->player_y] == 'E')
            mlx_loop_end(data->mlx);
        //mlx_string_put(data->mlx, data->win, 10, 30, 0xFF0000FF, ft_itoa(data->nb_move++));
        ft_printf("Numbers of Moves :%d\n", data->nb_move + 1);
    }
}

void move_down(mlx_t *data)
{
    int tmp;
    tmp = data->player_x;
    if (data->map[data->player_x + 1][data->player_y] != '1')
    {
        if (data->map[data->player_x + 1][data->player_y] == 'C')
            data->nb_coin++;
        if (data->nb_coin == data->coins)
            mlx_put_image_to_window(data->mlx, data->win, data->exit, data->end_y*32, data->end_x*32);
        mlx_put_image_to_window(data->mlx, data->win, data->player, data->player_y*32, (data->player_x + 1)*32);
        data->player_x++;
        data->map[tmp][data->player_y] = '0';
        mlx_put_image_to_window(data->mlx, data->win, data->ground, data->player_y*32, tmp*32);
        if (data->nb_coin == data->coins && data->map[data->player_x][data->player_y] == 'E')
            mlx_loop_end(data->mlx);
        //mlx_string_put(data->mlx, data->win, 10, 30, 0xFF0000FF, ft_itoa(data->nb_move++));
        ft_printf("Numbers of Moves :%d\n", data->nb_move + 1);
    }
}

void move_right(mlx_t *data)
{
    int tmp;
    tmp = data->player_y;
    if (data->map[data->player_x][data->player_y + 1] != '1')
    {
        if (data->map[data->player_x][data->player_y + 1] == 'C')
            data->nb_coin++;
        if (data->nb_coin == data->coins)
            mlx_put_image_to_window(data->mlx, data->win, data->exit, data->end_y*32, data->end_x*32);
        mlx_put_image_to_window(data->mlx, data->win, data->player, (data->player_y + 1)*32, data->player_x*32);
        data->player_y++;
        data->map[data->player_x][tmp] = '0';
        mlx_put_image_to_window(data->mlx, data->win, data->ground, tmp*32, data->player_x*32);
        if (data->nb_coin == data->coins && data->map[data->player_x][data->player_y] == 'E')
            mlx_loop_end(data->mlx);
        //mlx_string_put(data->mlx, data->win, 10, 30, 0xFF0000FF, ft_itoa(data->nb_move++));
        ft_printf("Numbers of Moves :%d\n", data->nb_move + 1);
    }
}

void move_left(mlx_t *data)
{
    int tmp;
    tmp = data->player_y;
    if (data->map[data->player_x][data->player_y - 1] != '1')
    {
        if (data->map[data->player_x][data->player_y - 1] == 'C')
            data->nb_coin += 1;
        if (data->nb_coin == data->coins)
            mlx_put_image_to_window(data->mlx, data->win, data->exit, data->end_y*32, data->end_x*32);
        mlx_put_image_to_window(data->mlx, data->win, data->player, (data->player_y - 1)*32, data->player_x*32);
        data->player_y--;
        data->map[data->player_x][tmp] = '0';
        mlx_put_image_to_window(data->mlx, data->win, data->ground, tmp*32, data->player_x*32);
        if (data->nb_coin == data->coins && data->map[data->player_x][data->player_y] == 'E')
            mlx_loop_end(data->mlx);
        //mlx_string_put(data->mlx, data->win, 10, 30, 0xFF0000FF, ft_itoa(data->nb_move++));
        ft_printf("Numbers of Moves :%d\n", data->nb_move + 1);
    }
}