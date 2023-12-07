/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:43:25 by codespace         #+#    #+#             */
/*   Updated: 2023/12/07 17:51:49 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_init(void)
{
	mlx_t *mlx;
	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
	{
		perror("Error init");
		return (EXIT_FAILURE);
	}

	mlx_loop(mlx);

	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}