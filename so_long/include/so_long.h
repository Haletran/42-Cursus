/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:25:27 by codespace         #+#    #+#             */
/*   Updated: 2024/01/18 14:57:06 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include "../../libft/libft.h"
# include "../MacroLibX/includes/mlx.h"
# define WIDTH 500
# define HEIGHT 500

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct
{
	void	*mlx;
	void	*win;
	char	**map;
	int		player_x;
	int		player_y;
	int		end_x;
	int		end_y;
	int	    fd;
}			mlx_t;

/* FUNCTIONS */
int			flood_fill(mlx_t *data);
int			check_file(char *filename);
char		*ft_strstr(char *str, char *to_find);
char		**initialize_map(int fd);
int			ft_strcmp(char *s1, char *s2);
int			global_checker(mlx_t *data);
int			ft_error(int choice);
int			isNotInSet(char c);

#endif
