/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 08:49:28 by dpoveda-          #+#    #+#             */
/*   Updated: 2021/10/26 08:49:29 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <mlx.h>

#include <stdio.h>

int		get_color(t_vars *vars, int x, int y)
{
	return (mlx_get_color_value(vars->mlx, vars->map->clrs[y][x]));
}

void	img_pixel_put(t_vars *vars, int x, int y)
{
	int	pixel;

	pixel = (y * vars->img->sz_l) + (x * 4);
	if (vars->img->endian == 1)
	{
		vars->img->addr[pixel + 0] = (vars->color >> 24);
		vars->img->addr[pixel + 1] = (vars->color >> 16) & 0xFF;
		vars->img->addr[pixel + 2] = (vars->color >> 8) & 0xFF;
		vars->img->addr[pixel + 3] = (vars->color) & 0xFF;
	}
	else if (vars->img->endian == 0)
	{
		vars->img->addr[pixel + 0] = (vars->color) & 0xFF;
		vars->img->addr[pixel + 1] = (vars->color >> 8) & 0xFF;
		vars->img->addr[pixel + 2] = (vars->color >> 16) & 0xFF;
		vars->img->addr[pixel + 3] = (vars->color >> 24);
	}
}
