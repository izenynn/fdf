/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:59:18 by dpoveda-          #+#    #+#             */
/*   Updated: 2021/10/26 17:59:20 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <limits.h>

void	handle_zoom(int keycode, t_vars *vars)
{
	if (keycode == KEY_Q)
	{
		if (vars->zoom > 0)
			vars->zoom -= ZOOM_SHIFT;
	}
	if (keycode == KEY_E)
	{
		if (vars->zoom < INT_MAX)
			vars->zoom += ZOOM_SHIFT;
	}
}

void	handle_move(int keycode, t_vars *vars)
{
	if (keycode == KEY_W)
		vars->shift_y += SHIFT;
	if (keycode == KEY_S)
		vars->shift_y -= SHIFT;
	if (keycode == KEY_A)
		vars->shift_x += SHIFT;
	if (keycode == KEY_D)
		vars->shift_x -= SHIFT;
}

void	handle_flattening(int keycode, t_vars *vars)
{
	if (keycode == KEY_PLUS)
	{
		if (vars->flat < 10)
			vars->flat += 0.1;
	}
	if (keycode == KEY_MINUS)
	{
		if (vars->flat > 0)
			vars->flat -= 0.1;
	}
}

void	handle_rot(int keycode, t_vars *vars)
{
	//
	if (vars)
		return ;
	//
	if (keycode == KEY_UP)
		;
	if (keycode == KEY_DOWN)
		;
	if (keycode == KEY_LEFT)
		;
	if (keycode == KEY_RIGHT)
		;
}
