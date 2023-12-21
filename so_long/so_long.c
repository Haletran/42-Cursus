/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:20:19 by codespace         #+#    #+#             */
/*   Updated: 2023/12/21 14:27:58 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

char	*so_long(char *file)
{
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		// ft_parse(line);
		free(line);
	}
	return (line);
}
int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		so_long(argv[1]);
	}
	else
		printf("%s", "Invalid input\nUsage : ./solong <map.ber>\n");
	return (0);
}
