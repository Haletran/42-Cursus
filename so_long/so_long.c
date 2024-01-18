/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptiste <baptiste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:25:12 by codespace         #+#    #+#             */
/*   Updated: 2024/01/18 23:24:56 by baptiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	key_hook(int key, void *param)
{
	if (key == 41)
		mlx_loop_end(param);
	if (key == 4)
		ft_printf("a");
	if (key == 22)
		ft_printf("s");
	if (key == 26)
		move_player(key);
	if (key == 7)
		ft_printf("d");
	return (0);
}

int	window_hook(int event, void *param)
{
	if (event == 0)
		mlx_loop_end(param);
	return (0);
}

int	main(int argc, char **argv)
{
	mlx_t	*mlx = malloc(sizeof(mlx_t));
	
	if (argc != 2 || argc > 3)
		return (ft_error(2));
	mlx->fd = open(argv[1], O_RDONLY);
	if (mlx->fd < 0 || !check_file(argv[1]))
		return (ft_error(1));
	if (!global_checker(mlx) || !flood_fill(mlx))
		return (ft_error(3));

	// MAIN MLX FUNCTION WIN
	int a = 0;
	while (mlx->map[a] != NULL)
		printf("%s", mlx->map[a++]);
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, mlx->height*32, mlx->width*32, "So_long");



	render_map(mlx);

	
	mlx_on_event(mlx->mlx, mlx->win, MLX_KEYDOWN, key_hook, mlx->mlx);
	mlx_on_event(mlx->mlx, mlx->win, MLX_WINDOW_EVENT, window_hook, mlx->mlx);
	mlx_loop(mlx->mlx);

	// WHEN EXITING WINDOW
	mlx_destroy_image(mlx->mlx, mlx->wall);
	mlx_destroy_image(mlx->mlx, mlx->ground);
	mlx_destroy_image(mlx->mlx, mlx->player);
	mlx_destroy_image(mlx->mlx, mlx->coin);
	mlx_destroy_image(mlx->mlx, mlx->exit);
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
	
	return (0);
}
