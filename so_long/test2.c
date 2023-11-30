#include <stdio.h>
#include <stdlib.h>
#include <MLX42/MLX42.h>
#include <string.h>

#define WIDTH 512
#define HEIGHT 512
static mlx_image_t *img;

int ft_hook(void *param)
{
    static int len = 0;
    mlx_t *mlx = param;

    if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
        mlx_close_window(mlx);
    else if (mlx_is_key_down(mlx, MLX_KEY_UP))
    {
        img->instances[0].y -= 5;
        printf("%s%d%s\n", "You moved ", len++, " times.");
    }
    else if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
    {
        img->instances[0].y += 5;
        printf("%s%d%s\n", "You moved ", len++, " times.");
    }
    else if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
    {
        img->instances[0].x -= 5;
        printf("%s%d%s\n", "You moved ", len++, " times.");
    }
    else if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
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

    img = mlx_new_image(mlx, 50, 50);
    memset(img->pixels, 200, img->width * img->height * sizeof(int32_t));

    if (mlx_image_to_window(mlx, img, 0, 0) < 0)
    {
        puts(mlx_strerror(mlx_errno));
        return (EXIT_FAILURE);
    }
    mlx_loop_hook(mlx, (void *)ft_hook, mlx);
    mlx_loop(mlx);

    mlx_terminate(mlx);
    return (EXIT_SUCCESS);
}