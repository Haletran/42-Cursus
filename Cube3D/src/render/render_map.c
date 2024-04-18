/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptiste <baptiste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:25:15 by bapasqui          #+#    #+#             */
/*   Updated: 2024/04/19 01:25:23 by baptiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void init_map(t_mlx *mlx)
{
    int fd;
    int i;

    i = 0;
    fd = open(mlx->map->path, O_RDONLY);
    if (!fd)
        return ;
    while (1)
    {
        mlx->map->map[i] = get_next_line(fd);
        if (!mlx->map->map[i])
            break;
        i++;
    }
    close(fd);
    draw_map(mlx);
}

void draw_map(t_mlx *mlx)
{
    int i;
    int j;

    i = 0;
    while (mlx->map->map[i])
    {
        j = 0;
        while (mlx->map->map[i][j])
        {
            if (mlx->map->map[i][j] == '1')
                mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->wall, j * 33, i * 33);
            else if (mlx->map->map[i][j] == 'W')
                mlx->player->angle = 3 * PI / 2;
            j++;
        }
        i++;
    }
}

/* void drawRays(t_mlx *mlx)
{


    
} */