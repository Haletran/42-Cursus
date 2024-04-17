/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:02:49 by bapasqui          #+#    #+#             */
/*   Updated: 2024/04/17 16:24:11 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../MacroLibX/includes/mlx.h"
# include "../lib/libft/libft.h"
# include <errno.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <fcntl.h>

/* DEFINE */
# define FOV 60
# define RAYS 300
# define PI 3.14159265358979323846

# define KEY_ESC 41
# define KEY_W 26
# define KEY_A 4
# define KEY_S 22
# define KEY_D 7

# define LEFT_ARROW 80
# define RIGHT_ARROW 79
# define UP_ARROW 82
# define DOWN_ARROW 81

# define MAP_PATH "/sgoinfre/goinfre/Perso/bapasqui/Common-Core/Cube3D/maps/map.cub"

/*STRUCTURES*/

typedef struct s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	void			*floor;
	void			*wall;
	struct s_player	*player;
	struct s_ray	*ray;
	struct s_map	*map;
}					t_mlx;

typedef struct s_player
{
	float			x;
	float			y;
	float			delta_x;
	float			delta_y;
	float			angle;
	double			dir;
	double			fov;
}					t_player;

typedef struct s_map
{
	int				*map2;
	char			**map;
	int				width;
	int				height;
}					t_map;

typedef struct s_ray
{
	double			x;
	double			y;
	double			dir;
	double			dist;
}					t_ray;

/* FUNCTIONS */
void draw_map(t_mlx *mlx);
void init_map(t_mlx *mlx);
t_mlx				*rotate_player(t_mlx *mlx, int angle);
void				render_player(t_mlx *mlx);
t_mlx				*init(t_mlx *mlx);
int					window_hook(int event, void *param);
int					key_hook(int key, void *param);

#endif