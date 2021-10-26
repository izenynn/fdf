/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 09:25:57 by dpoveda-          #+#    #+#             */
/*   Updated: 2021/10/22 09:26:00 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <mlx.h>
#include <libft/ft_mem.h>
#include <libft/ft_printf.h>
#include <stdlib.h>
#include <math.h>

#define MAX(a,b) (a > b) ? a : b

int	mlx_main(t_map *map)
{
	t_vars	*vars;

	ft_printf("Starting minilibx...\n");
	vars = (t_vars *)ft_calloc(1, sizeof(t_vars));
	vars->map = map;
	vars->img = (t_img *)ft_calloc(1, sizeof(t_img));

	vars->mlx = mlx_init();
	vars->img->img = mlx_new_image(vars->mlx, WIN_W, WIN_H);
	vars->img->addr = mlx_get_data_addr(vars->img->img,
		&vars->img->bpp, &vars->img->sz_l, &vars->img->endian);
	vars->win = mlx_new_window(vars->mlx, WIN_W, WIN_H, "fdf");
	//
	vars->zoom = MAX((WIN_W / map->w / 2), (WIN_H / map->h / 2));
	vars->rot = 0.8;
	vars->shift_x = WIN_W / 2;
	vars->shift_y = (WIN_H - map->h * vars->zoom) / 2;
	vars->iso = 1;
	//
	mlx_hook(vars->win, 2, 1L<<0, key_hook, vars);
	//mlx_key_hook(vars->win, key_hook, vars);
	//
	//mlx_loop_hook(vars->mlx, update, vars);
	draw(vars);
	mlx_loop(vars->mlx);
	//
	//free(vars->map);
	//free(vars->img); // mlx_destroy_img(vars->img);
	//free(vars);
	free_all(vars);
	return (EXIT_SUCCESS);
}
