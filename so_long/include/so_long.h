/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptiste <baptiste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:25:27 by codespace         #+#    #+#             */
/*   Updated: 2024/01/21 16:02:56 by baptiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include "../../libft/libft.h"
# include "../MacroLibX/includes/mlx.h"
# define WIDTH 1000
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
	int    width;
	int   height;
	int		player_x;
	int		player_y;
	int		end_x;
	int		end_y;
	int	    fd;
	void   *ground;
	void   *wall;
	void   *player;
	void   *exit;
	void   *coin;
}			mlx_t;

/* FUNCTIONS */
void render_map(mlx_t *data);
int			flood_fill(mlx_t *data);
int			check_file(char *filename);
char		*ft_strstr(char *str, char *to_find);
char		**initialize_map(int fd);
int			ft_strcmp(char *s1, char *s2);
int			global_checker(mlx_t *data);
int			ft_error(int choice);
int			isNotInSet(char c);
mlx_t *get_co(mlx_t *data);
void move_up(mlx_t *data);
void    get_var(mlx_t *data);
void move_down(mlx_t *data);
void move_right(mlx_t *data);
void move_left(mlx_t *data);

#endif
