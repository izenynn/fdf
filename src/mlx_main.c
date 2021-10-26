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

int	mlx_main(t_map *map)
{
	t_vars	*vars;

	ft_printf("Starting minilibx...\n");
	vars = (t_vars *)ft_calloc(1, sizeof(t_vars));
	if (!vars)
		err_exit("Error", MAL_ERROR);
	if (initialise_vars(vars, map))
	{
		free_all(vars);
		err_exit("Error", MAL_ERROR);
	}
	initialise_mlx(vars);
	mlx_hook(vars->win, 2, 1L << 0, key_hook, vars);
	mlx_hook(vars->win, 17, 1L << 17, close_win, vars);
	draw(vars);
	mlx_loop(vars->mlx);
	free_all(vars);
	return (EXIT_SUCCESS);
}
