/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:31:38 by dpoveda-          #+#    #+#             */
/*   Updated: 2021/10/24 12:31:40 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <libft/ft_mem.h>
#include <mlx.h>
#include <math.h>

void	draw_menu(t_vars *vars)
{
	int		y;
	void	*mlx;
	void	*win;

	mlx = vars->mlx;
	win = vars->win;
	y = 0;
	mlx_string_put(mlx, win, 15, y += 20, WHITE, "Controls:");
	mlx_string_put(mlx, win, 15, y += 50, WHITE, "Move: W, A, S, D");
	mlx_string_put(mlx, win, 15, y += 25, WHITE, "Zoom: Q / E");
	mlx_string_put(mlx, win, 15, y += 25, WHITE, "Flattening: - / +");
	mlx_string_put(mlx, win, 15, y += 25, WHITE, "Rotate: Arrows");
	mlx_string_put(mlx, win, 15, y += 25, WHITE, "Perspective:");
	mlx_string_put(mlx, win, 30, y += 25, WHITE, "- Isometric: I");
	mlx_string_put(mlx, win, 30, y += 25, WHITE, "- Parallel: P");
}

void	isometric(float *x, float *y, int z, t_vars *vars)
{
	int	prev_x;
	int	prev_y;

	if (!vars->iso)
		return ;
	/**x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;*/
	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(0.523599);
	*y = -z + (prev_x + prev_y) * sin(0.523599);
}

void	bresenham(float x, float y, float x1, float y1, t_vars *vars)
{
	float	x_step;
	float	y_step;
	int		max;
	int		z;
	int		z1;

	z = vars->map->z_mt[(int)y][(int)x];
	z1 = vars->map->z_mt[(int)y1][(int)x1];

	vars->color = get_color(vars, x, y);

	x *= vars->zoom;
	y *= vars->zoom;
	x1 *= vars->zoom;
	y1 *= vars->zoom;

	z *= (vars->zoom / 10) * vars->flat;
	z1 *= (vars->zoom / 10) * vars->flat;

	isometric(&x, &y, z, vars);
	isometric(&x1, &y1, z1, vars);

	x += vars->shift_x;
	x1 += vars->shift_x;
	y += vars->shift_y;
	y1 += vars->shift_y;

	x_step = x1 - x;
	y_step = y1 - y;

	max = (int)fmax(fabs(x_step), fabs(y_step));

	x_step /= max;
	y_step /= max;

	//vars->color = (z || z1) ? 0xff0000 : 0xffffff;

	while ((int)(x - x1) || (int)(y - y1))
	{
		img_pixel_put(vars, x, y);
		x += x_step;
		y += y_step;
	}
}

void	draw(t_vars *vars)
{
	int	x;
	int	y;

	ft_bzero(vars->img->addr, WIN_H * WIN_W * (vars->img->bpp / 8));
	if (vars->zoom)
	{
		y = -1;
		while (++y < vars->map->h)
		{
			x = -1;
			while (++x < vars->map->w)
			{
				if (x < vars->map->w - 1)
					bresenham(x, y, x + 1, y, vars);
				if (y < vars->map->h - 1)
					bresenham(x, y, x, y + 1, vars);
			}
		}
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
	draw_menu(vars);
	//mlx_destroy_image(vars->mlx, vars->img->img);
	//vars->img->img = mlx_new_image(vars->mlx, WIN_W, WIN_H);
	//vars->img->addr = mlx_get_data_addr(vars->img->img,
	//	&vars->img->bpp, &vars->img->sz_l, &vars->img->endian);
}
