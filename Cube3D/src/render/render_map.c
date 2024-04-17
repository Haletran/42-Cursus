/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:25:15 by bapasqui          #+#    #+#             */
/*   Updated: 2024/04/17 16:46:18 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void init_map(t_mlx *mlx)
{
    int fd;
    int i;

    i = 0;
    mlx->map = ft_calloc(1, sizeof(t_map));
    mlx->map->map = malloc(sizeof(char *) * 1000);
    fd = open(MAP_PATH, O_RDONLY);
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
                mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->wall, j * 32, i * 32);
            else if (mlx->map->map[i][j] == 'W')
                mlx->player->angle = 3 * PI / 2;
            j++;
        }
        i++;
    }
}