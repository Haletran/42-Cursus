/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptiste <baptiste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:25:27 by codespace         #+#    #+#             */
/*   Updated: 2024/01/17 22:54:40 by baptiste         ###   ########.fr       */
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
# include <unistd.h>
# include <string.h>

typedef struct
{
	void	*mlx;
	void	*win;
	char	**map;
	int		map_width;
	int		map_height;
	int		player_x;
	int		player_y;
	int		end_x;
	int		end_y;
	int		start_x;
	int		start_y;
}			mlx_t;

/* FUNCTIONS */
int check_file(char *filename);
char	*ft_strstr(char *str, char *to_find);
char		**initialize_map(int fd);
int			ft_strcmp(char *s1, char *s2);
int			global_checker(int fd);
int			ft_error(int choice);
int isNotInSet(char c);

#endif
