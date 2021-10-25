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

	x *= vars->zoom;
	y *= vars->zoom;
	x1 *= vars->zoom;
	y1 *= vars->zoom;

	x_step = x1 - x;
	y_step = y1 - y;

	max = (int)fmax(fabs(x_step), fabs(y_step));

	x_step /= max;
	y_step /= max;

	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(vars->mlx, vars->win, x, y, 0xffffff);
		x += x_step;
		y += y_step;
		//printf("x: %f, y: %f\n", x_step, y_step);
		if (x > WIN_W || y > WIN_H || x < 0 || y < 0)
			break ;
	}
}

void	draw(t_vars *vars)
{
	int	x;
	int	y;

	y = -1;
	while (++y < WIN_H)
	{
		x = -1;
		while (++x < WIN_W)
		{
			bresenham(x, y, x + 1, y, vars);
			bresenham(x, y, x, y + 1, vars);
		}
	}
}
