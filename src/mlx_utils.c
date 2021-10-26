/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 19:38:21 by dpoveda-          #+#    #+#             */
/*   Updated: 2021/10/26 19:38:22 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <libft/ft_mem.h>
#include <mlx.h>

#define MAX(a,b) (a > b) ? a : b

void	reset_vars(t_vars *vars)
{
	vars->zoom = MAX((WIN_W / vars->map->w / 2), (WIN_H / vars->map->h / 2));
	vars->shift_x = WIN_W / 2;
	vars->shift_y = (WIN_H - vars->map->h * vars->zoom) / 2;
	vars->rot = 0.8;
	vars->iso = 1;
	vars->flat = 1;
	vars->rot_x = 0;
	vars->rot_y = 0;
	vars->rot_z = 0;
}

int	initialise_vars(t_vars *vars, t_map *map)
{
	vars->map = map;
	vars->img = (t_img *)ft_calloc(1, sizeof(t_img));
	if (!vars->img)
		return (1);
	reset_vars(vars);
	return (0);
}

void	initialise_mlx(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->img->img = mlx_new_image(vars->mlx, WIN_W, WIN_H);
	vars->img->addr = mlx_get_data_addr(vars->img->img,
		&vars->img->bpp, &vars->img->sz_l, &vars->img->endian);
	vars->win = mlx_new_window(vars->mlx, WIN_W, WIN_H, "fdf");
}
