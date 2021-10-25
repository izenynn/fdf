/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 12:26:27 by dpoveda-          #+#    #+#             */
/*   Updated: 2021/10/25 12:26:28 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

static int	close_win(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	//free(vars->map);
	//free(vars->img);
	//free(vars);
	exit (EXIT_SUCCESS);
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	printf("Keycode: %d\n", keycode);
	if (keycode == KEY_ESC)
		;//close_win(vars);
	if (keycode == KEY_UP)
		vars->shift_y -= SHIFT;
	if (keycode == KEY_DOWN)
		vars->shift_y += SHIFT;
	if (keycode == KEY_LEFT)
		vars->shift_x -= SHIFT;
	if (keycode == KEY_RIGHT)
		vars->shift_x += SHIFT;
	if (keycode == KEY_Q)
		vars->rot += ROT_SHIFT;
	if (keycode == KEY_E)
		vars->rot -= ROT_SHIFT;
	mlx_clear_window(vars->mlx, vars->win);
	draw(vars);
	return (0);
}
