/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:17:34 by bapasqui          #+#    #+#             */
/*   Updated: 2024/01/16 19:15:46 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**stock_map(int fd)
{
    char **map;
    int i;
	map = malloc(100 * sizeof(char *));
	if (!map)
		return (NULL);
	i = 0;
	while (i < 100 - 1)
	{
		map[i] = get_next_line(fd);
		if (map[i] == NULL)
			break ;
		i++;
	}
	close(fd);
	return (map);
}