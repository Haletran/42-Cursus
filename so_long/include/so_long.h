/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:25:27 by codespace         #+#    #+#             */
/*   Updated: 2024/01/17 13:38:06 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include "../MacroLibX/includes/mlx.h"
# include "../../libft/libft.h"
# define WIDTH 500
# define HEIGHT 500

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct
{
    void* mlx;
    void* win;
    char **map;
    int map_width;
    int map_height;
    int player_x;
    int player_y;
} mlx_t;


/* FUNCTIONS */
char **initialize_mlx(int fd);
int	ft_strcmp(char *s1, char *s2);
char	**stock_map(int fd);
int global_checker(int fd);
int	ft_error(int choice);

#endif
