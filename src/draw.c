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

void	draw(int x, int y, int x1, int y1, t_vars *vars)
{
	float	x_step;
	float	y_step;
	int		max;

	x_step = x1 - x;
	y_step = y1 - y;
	max = MAX(ABS(x_step), ABS(y_step));

	x_step /= max;
	y_step /= max;

	while (x - x1 || y - y1)
	{
		mlx_pixel_put(vars->mlx, vars->win, x, y, 0xffffff);
		x += x_step;
		y += y_step;
	}
}
