/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptiste <baptiste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:47:37 by baptiste          #+#    #+#             */
/*   Updated: 2024/01/17 23:04:46 by baptiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//flood fill
mlx_t *get_co(mlx_t *data, char **map)
{
    data = malloc(sizeof(mlx_t));
    int x;
    int y;
    int tmp;

    x = 0;
    tmp = 0;
    y = 0;
    while(map[x] != NULL)
    {
        while(map[x][y] != '\n' && map[x][y] != '\0')
        {
            if (map[x][y] == 'P')
            {
                data->player_x = x;
                data->player_x = y;
                break ;
            }
            if (map[x][y] == 'E')
            {
                data->end_x = x;
                data->end_y = y;
                break ;
            }
            y++;
        }
        x++;
    }
    return (data);
}

int *flood_fill(mlx_t *data, int fd)
{
    data = malloc(sizeof(mlx_t));
    data->map = initialize_map(fd);
    
    
    
}







