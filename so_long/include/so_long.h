/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:25:27 by codespace         #+#    #+#             */
/*   Updated: 2024/01/22 10:21:58 by bapasqui         ###   ########.fr       */
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

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	char	**map;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		end_x;
	int		end_y;
	int		fd;
	void	*ground;
	void	*wall;
	void	*player;
	void	*exit;
	void	*coin;
	int		nb_move;
	int		coins;
	int		nb_coin;
	int		x;
	int		y;
}			t_mlx;

/* FUNCTIONS */
void		render_map(t_mlx *data);
int			flood_fill(t_mlx *data);
int			check_file(char *filename);
char		*ft_strstr(char *str, char *to_find);
char		**initialize_map(int fd);
int			ft_strcmp(char *s1, char *s2);
int			global_checker(t_mlx *data);
int			ft_error(int choice);
int			isnotinset(char c);
t_mlx		*get_co(t_mlx *data);
void		move_up(t_mlx *data);
void		get_var(t_mlx *data);
void		move_down(t_mlx *data);
void		move_right(t_mlx *data);
void		move_left(t_mlx *data);

#endif
