/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:14:44 by codespace         #+#    #+#             */
/*   Updated: 2023/12/07 17:51:55 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Check if the map is valid
// Transform it into pixels (sprites)
// Render the map

int	ft_check_validity(char **map)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = (int)ft_strlen(map[0]);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'C'
				&& map[i][j] != 'E' && map[i][j] != 'P')
				return (0);
			j++;
		}
		if ((int)ft_strlen(map[i]) != len)
			return (0);
		i++;
	}
	return (1);
}
int	ft_parse(char *line)
{
}

int	ft_render(char **map);

int	ft_transform(void);