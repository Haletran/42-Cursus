/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptiste <baptiste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:47:37 by baptiste          #+#    #+#             */
/*   Updated: 2024/01/21 17:37:22 by baptiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//flood fill
mlx_t *get_mapwh(mlx_t *data)
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

mlx_t *get_co(mlx_t *data)
{
    int x;
    int y;

    x = 0;
    y = 0;
    get_mapwh(data);
    while(data->map[x] != NULL)
    {
        while(data->map[x][y] != '\0')
        {
            if (data->map[x][y] == 'E')
            {
                data->end_x = x;
                data->end_y = y;
            }
            if (data->map[x][y] == 'P')
            {
                data->player_x = x;
                data->player_y = y;
            }
            if (data->map[x][y] == 'C')
                data->coins++;
            y++;
        }
        y = 0;
        x++;
    }
    return (data);
}




int flood_fill(mlx_t *data)
{
    data = get_co(data);
    return (1);
}







