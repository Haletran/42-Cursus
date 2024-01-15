/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:25:12 by codespace         #+#    #+#             */
/*   Updated: 2024/01/15 16:34:02 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (0);

	void *mlx = mlx_init();
	void *win = mlx_new_window(mlx, 400, 400, "Hello world!");

	mlx_destroy_window(mlx, win);
	mlx_destroy_display(mlx);
}