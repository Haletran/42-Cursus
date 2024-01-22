/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:17:34 by bapasqui          #+#    #+#             */
/*   Updated: 2024/01/22 15:57:22 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**initialize_map(t_mlx *data)
{
	int		i;

	i = 0;
	data->map = malloc(100 * sizeof(char *));
	if (!data->map)
	{
		ft_free(data);
		return (NULL);
	}
	while (1)
	{
		data->map[i] = get_next_line(data->fd);
		if (data->map[i] == NULL)
			break ;
		i++;
	}
	close(data->fd);
	return (data->map);
}
