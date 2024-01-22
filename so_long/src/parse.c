/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:17:34 by bapasqui          #+#    #+#             */
/*   Updated: 2024/01/22 12:34:51 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**initialize_map(int fd)
{
	int		i;
	t_mlx	*new_mlx;

	i = 0;
	new_mlx = malloc(sizeof(t_mlx));
	if (!new_mlx)
		return (NULL);
	new_mlx->map = malloc(100 * sizeof(char *));
	if (!new_mlx->map)
		return (NULL);
	while (1)
	{
		new_mlx->map[i] = get_next_line(fd);
		if (new_mlx->map[i] == NULL)
			break ;
		i++;
	}
	close(fd);
	return (new_mlx->map);
}
