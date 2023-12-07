/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:28:15 by codespace         #+#    #+#             */
/*   Updated: 2023/12/07 16:02:51 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <MLX42/MLX42.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 1000
#define HEIGHT 500

static mlx_image_t *img;
static mlx_image_t *img2;

// HAndle moving the player
int ft_hook(void *param)
{
    static int len = 0;
    mlx_t *mlx;

    mlx = param;
    if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
        mlx_close_window(mlx);
    else if (mlx_is_key_down(mlx, MLX_KEY_UP) || mlx_is_key_down(mlx,
                                                                 MLX_KEY_W))
    {
        img->instances[0].y -= 5;
        printf("%s%d%s\n", "You moved ", len++, " times.");
    }
    else if (mlx_is_key_down(mlx, MLX_KEY_DOWN) || mlx_is_key_down(mlx,
                                                                   MLX_KEY_S))
    {
        img->instances[0].y += 5;
        printf("%s%d%s\n", "You moved ", len++, " times.");
    }
    else if (mlx_is_key_down(mlx, MLX_KEY_LEFT) || mlx_is_key_down(mlx,
                                                                   MLX_KEY_A))
    {
        img->instances[0].x -= 5;
        printf("%s%d%s\n", "You moved ", len++, " times.");
    }
    else if (mlx_is_key_down(mlx, MLX_KEY_RIGHT) || mlx_is_key_down(mlx,
                                                                    MLX_KEY_D))
    {
        img->instances[0].x += 5;
        printf("%s%d%s\n", "You moved ", len++, " times.");
    }
    return (len);
}

int main(void)
{
    mlx_t *mlx;

    if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
    {
        puts(mlx_strerror(mlx_errno));
        return (EXIT_FAILURE);
    }

    // img = mlx_new_image(mlx, 10, 10);
    // memset(img->pixels, 200, img->width * img->height * sizeof(int32_t));

    // HANDLE Image
    mlx_texture_t *texture = mlx_load_png("images/player.png");
    img = mlx_texture_to_image(mlx, texture);
    if (mlx_image_to_window(mlx, img, 500, 250) < 0)
    {
        puts(mlx_strerror(mlx_errno));
        return (EXIT_FAILURE);
    }

    mlx_texture_t *texture2 = mlx_load_png("images/coin.png");
    img2 = mlx_texture_to_image(mlx, texture);
    if (mlx_image_to_window(mlx, img2, 200, 100) < 0)
    {
        puts(mlx_strerror(mlx_errno));
        return (EXIT_FAILURE);
    }

    mlx_loop_hook(mlx, (void *)ft_hook, mlx);
    mlx_loop(mlx);

    // EXIT PROGRAM
    mlx_delete_image(mlx, img);
    mlx_delete_texture(texture);
    mlx_delete_image(mlx, img2);
    mlx_delete_texture(texture2);
    mlx_terminate(mlx);
    return (EXIT_SUCCESS);
}