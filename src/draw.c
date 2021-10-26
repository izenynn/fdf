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

void	isometric(float *x, float *y, int z, t_vars *vars)
{
	*x = (*x - *y) * cos(vars->rot);
	*y = (*x + *y) * sin(vars->rot) - z;
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
		if (x >= WIN_W || y >= WIN_H || x < 0 || y < 0)
			break ;
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
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
	//mlx_destroy_image(vars->mlx, vars->img->img);
	//vars->img->img = mlx_new_image(vars->mlx, WIN_W, WIN_H);
	//vars->img->addr = mlx_get_data_addr(vars->img->img,
	//	&vars->img->bpp, &vars->img->sz_l, &vars->img->endian);
}
