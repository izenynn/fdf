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

#include <stdio.h>

#define ABS(a) ((a < 0) ? (-(a)) : (a))

void	draw_menu(t_vars *vars)
{
	int		y;
	void	*mlx;
	void	*win;

	mlx = vars->mlx;
	win = vars->win;
	y = 0;
	mlx_string_put(mlx, win, 15, y += 15, WHITE, "Controls:");
	mlx_string_put(mlx, win, 15, y += 50, WHITE, "Reset: R");
	mlx_string_put(mlx, win, 15, y += 25, WHITE, "Move: W, A, S, D");
	mlx_string_put(mlx, win, 15, y += 25, WHITE, "Zoom: Arrows");
	mlx_string_put(mlx, win, 15, y += 25, WHITE, "Flattening: + / -");
	mlx_string_put(mlx, win, 15, y += 25, WHITE, "Rotate:");
	mlx_string_put(mlx, win, 30, y += 25, WHITE, "  x (+ / -): U / J");
	mlx_string_put(mlx, win, 30, y += 25, WHITE, "  y (+ / -): I / K");
	mlx_string_put(mlx, win, 30, y += 25, WHITE, "  z (+ / -): O / L");
	mlx_string_put(mlx, win, 15, y += 25, WHITE, "Perspective:");
	mlx_string_put(mlx, win, 30, y += 25, WHITE, "  Isometric: I");
	mlx_string_put(mlx, win, 30, y += 25, WHITE, "  Parallel: P");
}

void	bresenham(t_vars *vars, t_point start, t_point end)
{
	t_point	cur;
	t_point	sign;
	t_point	delta;
	int	error[2];

	delta.x = ABS(end.x - start.x);
	delta.y = ABS(end.y - start.y);
	sign.x = -1;
	sign.y = -1;
	if (start.x < end.x)
		sign.x = 1;
	if (start.y < end.y)
		sign.y = 1;
	error[0] = delta.x - delta.y;
	cur = start;
	while (cur.x != end.x || cur.y != end.y)
	{
		img_pixel_put(vars, cur.x, cur.y, get_color(cur, start, end, delta));
		error[1] = error[0] * 2;
		if (error[1] > -delta.y)
		{
			error[0] -= delta.y;
			cur.x += sign.x;
		}
		if (error[1] < delta.x)
		{
			error[0] += delta.x;
			cur.y += sign.y;
		}
	}
}
/*
	float	x_step;
	float	y_step;
	int		max;

	float	z;
	float	z1;

	z = vars->map->z_mt[(int)y][(int)x];
	z1 = vars->map->z_mt[(int)y1][(int)x1];

	//vars->color = get_color(vars, x, y);
	start.x = x;
	end.x = x1;
	start.y = y;
	end.y = y1;

	delta.x = fabs(end.x - start.x);
	delta.y = end.y - start.y;

	cur = start;

	// finish with t_point

	x *= vars->zoom;
	y *= vars->zoom;
	x1 *= vars->zoom;
	y1 *= vars->zoom;

	z *= (vars->zoom / 10) * vars->flat;
	z1 *= (vars->zoom / 10) * vars->flat;

	rot_x(vars, &y, &z);
	rot_x(vars, &y1, &z1);
	rot_y(vars, &x, &z);
	rot_y(vars, &x1, &z1);
	rot_z(vars, &x, &y);
	rot_z(vars, &x1, &y1);

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

	while ((int)(x - x1) || (int)(y - y1))
	{
		vars->color = get_color(vars, cur, start, end, delta);
		img_pixel_put(vars, x, y);
		x += x_step;
		y += y_step;
	}
}*/

t_point	get_coords(t_vars *vars, t_point point)
{
	point.x *= vars->zoom;
	point.y *= vars->zoom;
	point.z *= (vars->zoom / 10) * vars->flat;
	rot_x(vars, &point.y, &point.z);
	rot_y(vars, &point.x, &point.z);
	rot_z(vars, &point.x, &point.y);
	isometric(vars, &point.x, &point.y, point.z);
	point.x += vars->shift_x;
	point.y += vars->shift_y;
	return (point);
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
					bresenham(vars,
						get_coords(vars, new_point(x, y, vars)),
						get_coords(vars, new_point(x + 1, y, vars)));
				if (y < vars->map->h - 1)
					bresenham(vars,
						get_coords(vars, new_point(x, y, vars)),
						get_coords(vars, new_point(x, y + 1, vars)));
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
