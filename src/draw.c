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
#include <mlx.h>
#include <math.h>

#include <stdio.h>

void	bresenham(float x, float y, float x1, float y1, t_vars *vars)
{
	float	x_step;
	float	y_step;
	int		max;
	int		z;
	int		z1;

	z = vars->map->z_mt[(int)y][(int)x];
	z1 = vars->map->z_mt[(int)y1][(int)x1];

	x *= vars->zoom;
	y *= vars->zoom;
	x1 *= vars->zoom;
	y1 *= vars->zoom;

	x_step = x1 - x;
	y_step = y1 - y;

	max = (int)fmax(fabs(x_step), fabs(y_step));

	x_step /= max;
	y_step /= max;

	vars->color = (z > 0) ? 0xff0000 : 0xffffff;

	while ((int)(x - x1) || (int)(y - y1))
	{
		if (x > WIN_W || y > WIN_H || x < 0 || y < 0)
			break ;
		//vars->img->addr = mlx_get_data_addr(vars->img->img,
		//	&vars->img->bpp, &vars->img->sz_l, &vars->img->endian);
		//vars->color = mlx_get_color_value(vars->mlx, 0xff00ff);
		//vars->color = mlx_get_color_value(vars->mlx, vars->map->clrs[y][x]);
		mlx_pixel_put(vars->mlx, vars->win, x, y, vars->color);
		x += x_step;
		y += y_step;
		//printf("x: %f, y: %f\n", x_step, y_step);
	}
}

void	draw(t_vars *vars)
{
	int	x;
	int	y;

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
