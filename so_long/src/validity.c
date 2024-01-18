/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:47:37 by baptiste          #+#    #+#             */
/*   Updated: 2024/01/18 15:02:10 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//flood fill
mlx_t *get_co(mlx_t *data)
{
    int x;
    int y;

    x = 0;
    y = 0;
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
            y++;
        }
        y = 0;
        x++;
    }
    return (data);
}

int flood_fill(mlx_t *data)
{
    //data->map = initialize_map(data->fd);
    data = get_co(data);
    
    
    ft_printf("Player : %c\n", data->map[data->player_x][data->player_y]);
    ft_printf("Ending : %c\n", data->map[data->end_x][data->end_y]);

    ft_printf("Player Position : X=%d Y=%d\n", data->player_x, data->player_y);
    ft_printf("Ending Position : X=%d Y=%d\n", data->end_x, data->end_y);
    
    return (1);
}







