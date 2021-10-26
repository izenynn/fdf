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
#include <math.h>

void	isometric(t_vars *vars, int *x, int *y, int z)
{
	int	prev_x;
	int	prev_y;

	if (!vars->iso)
		return ;
	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(0.523599);
	*y = -z + (prev_x + prev_y) * sin(0.523599);
}

void	rot_x(t_vars *vars, int *y, int *z)
{
	float	prev_y;

	prev_y = *y;
	*y = (prev_y * cos(vars->rot_x)) + (*z * sin(vars->rot_x));
	*z = (-prev_y * sin(vars->rot_x)) + (*z * cos(vars->rot_x));
}

void	rot_y(t_vars *vars, int *x, int *z)
{
	float	prev_x;

	prev_x = *x;
	*x = (*x * cos(vars->rot_y)) + (*z * sin(vars->rot_y));
	*z = (-prev_x * sin(vars->rot_y)) + (*z * cos(vars->rot_y));
}

void	rot_z(t_vars *vars, int *x, int *y)
{
	float	prev_x;

	prev_x = *x;
	*x = (*x * cos(vars->rot_z)) - (*y * sin(vars->rot_z));
	*y = (prev_x * sin(vars->rot_z)) + (*y * cos(vars->rot_z));
}

void	img_pixel_put(t_vars *vars, int x, int y, int color)
{
	int	pixel;

	if (y >= WIN_H || x >= WIN_W || y < 0 || x < 0)
		return ;
	pixel = (y * vars->img->sz_l) + (x * 4);
	if (vars->img->endian == 1)
	{
		vars->img->addr[pixel + 0] = (color >> 24);
		vars->img->addr[pixel + 1] = (color >> 16) & 0xFF;
		vars->img->addr[pixel + 2] = (color >> 8) & 0xFF;
		vars->img->addr[pixel + 3] = (color) & 0xFF;
	}
	else if (vars->img->endian == 0)
	{
		vars->img->addr[pixel + 0] = (color) & 0xFF;
		vars->img->addr[pixel + 1] = (color >> 8) & 0xFF;
		vars->img->addr[pixel + 2] = (color >> 16) & 0xFF;
		vars->img->addr[pixel + 3] = (color >> 24);
	}
}
