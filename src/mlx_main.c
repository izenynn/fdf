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
#include <stdlib.h>

int	mlx_main(t_map *map)
{
	t_vars	*vars;

	vars = (t_vars *)ft_calloc(1, sizeof(t_vars));
	vars->map = map;
	vars->img = (t_img *)ft_calloc(1, sizeof(t_img));

	vars->mlx = mlx_init();
	vars->img->img = mlx_new_image(vars->mlx, WIN_W, WIN_H);
	vars->win = mlx_new_window(vars->mlx, WIN_W, WIN_H, "fdf");
	//
	vars->zoom = 20;
	//
	mlx_hook(vars->win, 2, 1L<<0, key_hook, vars);
	//mlx_key_hook(vars->win, key_hook, vars);
	//
	//mlx_loop_hook(vars->mlx, update, vars);
	mlx_loop(vars->mlx);
	//
	//free(vars->map);
	//free(vars->img); // mlx_destroy_img(vars->img);
	//free(vars);
	return (EXIT_SUCCESS);
}
