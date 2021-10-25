/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 12:54:59 by dpoveda-          #+#    #+#             */
/*   Updated: 2021/10/25 12:55:01 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <mlx.h>

static int	draw(t_vars *vars)
{
	int	x;
	int	y;

	x = -1;
	while (++x < WIN_W / 4)
	{
		y = -1;
		while (++y < WIN_H / 4)
		{
			//vars->img->addr;
			mlx_pixel_put(vars->mlx, vars->win, x + WIN_W / 4, y + WIN_H / 4, 0x0000ff00);
		}
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
	return (0);
}

int	update(t_vars *vars)
{
	draw(vars);
	return (0);
}
