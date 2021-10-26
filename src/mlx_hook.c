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

static void	close_win(t_vars *vars)
{
	free_all(vars);
	exit (EXIT_SUCCESS);
}

int	key_hook(int keycode, t_vars *vars)
{
	printf("Keycode: %d\n", keycode);
	if (keycode == KEY_ESC)
		close_win(vars);
	if (keycode == KEY_W)
		vars->shift_y += SHIFT;
	if (keycode == KEY_S)
		vars->shift_y -= SHIFT;
	if (keycode == KEY_A)
		vars->shift_x += SHIFT;
	if (keycode == KEY_D)
		vars->shift_x -= SHIFT;
	if (keycode == KEY_Q)
		vars->zoom -= ZOOM_SHIFT;
	if (keycode == KEY_E)
		vars->zoom += ZOOM_SHIFT;
	if (keycode == KEY_UP)
		vars->rot += ROT_SHIFT;
	if (keycode == KEY_DOWN)
		vars->rot -= ROT_SHIFT;
	//mlx_clear_window(vars->mlx, vars->win);
	draw(vars);
	//mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	return (0);
}
