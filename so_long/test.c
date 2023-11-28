#include "minilibx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define WIDTH 500
#define HEIGHT 500

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}			t_vars;

/*int	print_square(t_vars *vars)
{
	int			x;
	int			y;
	int			size;
	int			i;
	int			c;
	int			c;
	int			c;
	int			c;
	int			c;
	static int	len = 0;

	x = 100;
	y = 100;
	size = 100;
	while (size > 0)
	{
		i = 0;
		while (i < size)
		{
			mlx_pixel_put(vars->mlx, vars->win, x + i, y, 0xFFFFFF);
			mlx_pixel_put(vars->mlx, vars->win, x + i, y + size, 0xFFFFFF);
			mlx_pixel_put(vars->mlx, vars->win, x, y + i, 0xFFFFFF);
			mlx_pixel_put(vars->mlx, vars->win, x + size, y + i, 0xFFFFFF);
			i++;
		}
		x++;
		y++;
		size -= 1;
	}
	return (0);
}*/

int	handle_key_press(int keycode, void *param, t_vars *vars)
{
	static int len = 0;
	if (keycode == 'w' || keycode == 'a' || keycode == 's' || keycode == 'd')
	{
		++len;
	}
	printf("%s%d%s\n", "You moved ", len, " times.");
	return (len);
}

int	close_program(t_vars *vars)
{
	(void)vars;
	exit(0);
	return (0);
}
int	main(void)
{
	t_vars vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "So_Long");

	mlx_hook(vars.win, 17, 0L, close_program, &vars);
	mlx_key_hook(vars.win, handle_key_press, 0);
	mlx_string_put(vars.mlx, vars.win, 220, 20, 0xffffff, "Hello user");
	mlx_loop(vars.mlx);
	return (0);
}