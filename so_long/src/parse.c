/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:17:34 by bapasqui          #+#    #+#             */
/*   Updated: 2024/01/17 13:54:37 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char **initialize_mlx(int fd)
{
	int i;

	i = 0;
    mlx_t *new_mlx = malloc(sizeof(mlx_t));
	if (!new_mlx)
        return NULL;

    new_mlx->map = malloc(100 * sizeof(char *));
    if (!new_mlx->map)
        return NULL;
    while ((new_mlx->map[i] = get_next_line(fd)) != NULL)
        i++;

    close(fd);
    return (new_mlx->map);
}

