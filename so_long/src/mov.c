/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 21:51:06 by baptiste          #+#    #+#             */
/*   Updated: 2024/01/23 19:08:43 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	handle_mv(t_mlx *data)
{
	if (data->nb_move >= 0 && data->nb_move < 10)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->wall, 0, 0);
		mlx_string_put(data->mlx, data->win, 10, 28, 0xFFFFFFFF,
			ft_itoa(data->nb_move++));
	}
	else if (data->nb_move >= 10)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->wall, 96, 0);
		mlx_put_image_to_window(data->mlx, data->win, data->wall, 64, 0);
		mlx_put_image_to_window(data->mlx, data->win, data->wall, 32, 0);
		mlx_put_image_to_window(data->mlx, data->win, data->wall, 0, 0);
		mlx_string_put(data->mlx, data->win, 10, 28, 0xFFFFFFFF,
			ft_itoa(data->nb_move++));
	}
}

void	move_up(t_mlx *data)
{
	int	tmp;

	tmp = data->player_x;
	if (data->map[data->player_x - 1][data->player_y] != '1')
	{
		if (data->map[data->player_x - 1][data->player_y] == 'C')
		{
			data->nb_coin += 1;
			data->map[data->player_x - 1][data->player_y] = '0';
		}
		if (data->map[data->player_x - 1][data->player_y] == 'Y')
			mlx_loop_end(data->mlx);
		if (data->nb_coin == data->coins)
			mlx_put_image_to_window(data->mlx, data->win, data->exit,
				data->end_y * 32, data->end_x * 32);
		mlx_put_image_to_window(data->mlx, data->win, data->player_back,
			data->player_y * 32, (data->player_x - 1) * 32);
		data->player_x--;
		/* data->map[tmp][data->player_y] = '0'; */
		mlx_put_image_to_window(data->mlx, data->win, data->ground,
			data->player_y * 32, tmp * 32);
		if (data->nb_coin == data->coins
			&& data->map[data->player_x][data->player_y] == 'E')
			mlx_loop_end(data->mlx);
		handle_mv(data);
	}
}

void	move_down(t_mlx *data)
{
	int	tmp;

	tmp = data->player_x;
	if (data->map[data->player_x + 1][data->player_y] != '1')
	{
		if (data->map[data->player_x + 1][data->player_y] == 'C')
		{
			data->nb_coin += 1;
			data->map[data->player_x + 1][data->player_y] = '0';
		}
		if (data->map[data->player_x + 1][data->player_y] == 'Y')
			mlx_loop_end(data->mlx);
		if (data->nb_coin == data->coins)
			mlx_put_image_to_window(data->mlx, data->win, data->exit,
				data->end_y * 32, data->end_x * 32);
		mlx_put_image_to_window(data->mlx, data->win, data->player_front,
			data->player_y * 32, (data->player_x + 1) * 32);
		data->player_x++;
		/* data->map[tmp][data->player_y] = '0'; */
		mlx_put_image_to_window(data->mlx, data->win, data->ground,
			data->player_y * 32, tmp * 32);
		if (data->nb_coin == data->coins
			&& data->map[data->player_x][data->player_y] == 'E')
			mlx_loop_end(data->mlx);
		handle_mv(data);
	}
}

void	move_right(t_mlx *data)
{
	int	tmp;

	tmp = data->player_y;
	if (data->map[data->player_x][data->player_y + 1] != '1')
	{
		if (data->map[data->player_x][data->player_y + 1] == 'C')
		{
			data->nb_coin += 1;
			data->map[data->player_x][data->player_y + 1] = '0';
		}
		if (data->map[data->player_x][data->player_y + 1] == 'Y')
			mlx_loop_end(data->mlx);
		if (data->nb_coin == data->coins)
			mlx_put_image_to_window(data->mlx, data->win, data->exit,
				data->end_y * 32, data->end_x * 32);
		mlx_put_image_to_window(data->mlx, data->win, data->player,
			(data->player_y + 1) * 32, data->player_x * 32);
		data->player_y++;
		/* data->map[data->player_x][tmp] = '0'; */
		mlx_put_image_to_window(data->mlx, data->win, data->ground, tmp * 32,
			data->player_x * 32);
		if (data->nb_coin == data->coins
			&& data->map[data->player_x][data->player_y] == 'E')
			mlx_loop_end(data->mlx);
		handle_mv(data);
	}
}

void	move_left(t_mlx *data)
{
	int	tmp;

	tmp = data->player_y;
	if (data->map[data->player_x][data->player_y - 1] != '1')
	{
		if (data->map[data->player_x][data->player_y - 1] == 'C')
		{
			data->nb_coin += 1;
			data->map[data->player_x][data->player_y - 1] = '0';
		}
		if (data->map[data->player_x][data->player_y - 1] == 'Y')
			mlx_loop_end(data->mlx);
		if (data->nb_coin == data->coins)
			mlx_put_image_to_window(data->mlx, data->win, data->exit,
				data->end_y * 32, data->end_x * 32);
		mlx_put_image_to_window(data->mlx, data->win, data->player_flip,
			(data->player_y - 1) * 32, data->player_x * 32);
		data->player_y--;
		mlx_put_image_to_window(data->mlx, data->win, data->ground, tmp * 32,
			data->player_x * 32);
		if (data->nb_coin == data->coins
			&& data->map[data->player_x][data->player_y] == 'E')
			mlx_loop_end(data->mlx);
		handle_mv(data);
	}
}
