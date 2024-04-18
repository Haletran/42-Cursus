/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptiste <baptiste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:37:15 by bapasqui          #+#    #+#             */
/*   Updated: 2024/04/19 01:03:23 by baptiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_mlx	*init(t_mlx *mlx, char **str)
{   
    int img_width = 32;
    int img_height = 32;
    mlx->map = ft_calloc(1, sizeof(t_map));
    mlx->map->map = malloc(sizeof(char *) * 1000);
    mlx->map->path = ft_strdup(str[1]);
    mlx->img = mlx_png_file_to_image(mlx->mlx, "images/player.png", &img_width, &img_height);
    //mlx->floor = mlx_png_file_to_image(mlx->mlx, "images/wall.png", &img_width, &img_height);
    mlx->wall = mlx_png_file_to_image(mlx->mlx, "images/floor.png", &img_width, &img_height);
    mlx->player = ft_calloc(1, sizeof(t_player));
    mlx->player->x = 40;
    mlx->player->y = 40;
    mlx->player->angle = 0;
    mlx->player->delta_x = cos(mlx->player->angle) * 5;
    mlx->player->delta_y = sin(mlx->player->angle) * 5;
    return (mlx);
}