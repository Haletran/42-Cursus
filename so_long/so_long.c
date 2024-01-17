/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:25:12 by codespace         #+#    #+#             */
/*   Updated: 2024/01/17 13:07:26 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	key_hook(int key, void *param)
{
	if (key == 41)
		mlx_loop_end(param);
	return (0);
}

int window_hook(int event, void *param)
{
	if (event == 0)
		mlx_loop_end(param);
	return (0);


}

int	main(int argc, char **argv)
{
	mlx_t mlx;
	int		fd;

	if (argc != 2 || argc > 3)
		return (ft_error(2));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (ft_error(1));
	if (!global_checker(fd))
		return (ft_error(3));
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 400, 400, "So_long");
	
	mlx_on_event(mlx.mlx, mlx.win, MLX_KEYDOWN, key_hook, mlx.mlx);
	mlx_on_event(mlx.mlx, mlx.win, MLX_WINDOW_EVENT, window_hook, mlx.mlx);
	mlx_loop(mlx.mlx);
	mlx_destroy_window(mlx.mlx, mlx.win);
	mlx_destroy_display(mlx.mlx);
	return (0);
}
