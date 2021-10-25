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

int	key_hook(int keycode, t_vars *vars)
{
	printf("Keycode: %d\n", keycode);
	return (0);
}

int	close_win(int keycode, t_vars *vars)
{
	/*if (keycode == KEY_ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		//free(vars->map);
		//free(vars->img);
		//free(vars);
		exit (EXIT_SUCCESS);
	}*/
	return (0);
}
