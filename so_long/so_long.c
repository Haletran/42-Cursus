/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptiste <baptiste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:25:12 by codespace         #+#    #+#             */
/*   Updated: 2024/01/21 16:24:32 by baptiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	key_hook(int key, void *param)
{
	mlx_t *mlx;
	mlx = param;
	//mlx_string_put(mlx->mlx, mlx->win, 10, 10, 0xFFFFFFFF, ft_itoa(data->nb_move)); 
	if (key == 41)
		mlx_loop_end(mlx->mlx);
	if (key == 4)
		move_left(mlx);
	if (key == 22)
		move_down(mlx);
	if (key == 26)
		move_up(mlx);
	if (key == 7)
		move_right(mlx);
	return (0);
}

int	window_hook(int event, void *param)
{
	if (event == 0)
		mlx_loop_end(param);
	return (0);
}

void rendering(mlx_t *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, mlx->height*32, mlx->width*32, "So_long");
	get_var(mlx);
	render_map(mlx);
	mlx_on_event(mlx->mlx, mlx->win, MLX_KEYDOWN, key_hook, mlx);
	mlx_on_event(mlx->mlx, mlx->win, MLX_WINDOW_EVENT, window_hook, mlx);
	mlx_loop(mlx->mlx);

	// WHEN EXITING WINDOW
	mlx_destroy_image(mlx->mlx, mlx->wall);
	mlx_destroy_image(mlx->mlx, mlx->ground);
	mlx_destroy_image(mlx->mlx, mlx->player);
	mlx_destroy_image(mlx->mlx, mlx->coin);
	mlx_destroy_image(mlx->mlx, mlx->exit);
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
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

	int a = 0;
	while (mlx->map[a] != NULL)
		printf("%s", mlx->map[a++]);

	rendering(mlx);

}
