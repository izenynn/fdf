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
	t_img	*img;
	char	*buff;
	int		pixel;
	int		color;

	img = vars->img;
	buff = mlx_get_data_addr(img->img, &img->bpp, &img->sz_l, &img->endian);
	y = -1;
	while (++y < WIN_H)
	{
		x = -1;
		while (++x < WIN_W)
		{
			//mlx_pixel_put(vars->mlx, vars->win, x + WIN_W / 4, y + WIN_H / 4, 0x0000ff00);
			//color = mlx_get_color_value(vars->mlx, vars->map->clrs[y][x]);
			color = mlx_get_color_value(vars->mlx, 0xff00ff);
			pixel = (y * img->sz_l) + (x * 4);
			if (img->endian == 1)
			{
				buff[pixel + 0] = (color >> 24);
				buff[pixel + 1] = (color >> 16) & 0xFF;
				buff[pixel + 2] = (color >> 8) & 0xFF;
				buff[pixel + 3] = (color) & 0xFF;
			}
			else if (img->endian == 0)
			{
				buff[pixel + 0] = (color) & 0xFF;
				buff[pixel + 1] = (color >> 8) & 0xFF;
				buff[pixel + 2] = (color >> 16) & 0xFF;
				buff[pixel + 3] = (color >> 24);
			}
		}
	}
	mlx_put_image_to_window(vars->mlx, vars->win, img->img, 0, 0);
	return (0);
}

int	update(t_vars *vars)
{
	draw(vars);
	return (0);
}
