/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:25:12 by codespace         #+#    #+#             */
/*   Updated: 2024/01/15 16:53:21 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	key_hook(int key, void *param)
{
	if (key == 41)
		mlx_loop_end(param);
	return (0);
}

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*win;

	if (argc == 2)
		return (0);
	(void)argv;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "Hello world!");
	mlx_on_event(mlx, win, MLX_KEYDOWN, key_hook, mlx);
	mlx_loop(mlx);
	mlx_destroy_window(mlx, win);
	mlx_destroy_display(mlx);
}
