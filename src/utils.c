/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 13:54:38 by dpoveda-          #+#    #+#             */
/*   Updated: 2021/10/21 13:54:39 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <mlx.h>
#include <stdlib.h>

void	free_split(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}

void	free_vars(t_vars *vars)
{
	free_map(vars->map);
	if (vars->img)
		free(vars->img);
	free(vars);

}

void	free_all(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_image(vars->mlx, vars->img->img);
	free_vars(vars);
}

t_point	new_point(int x, int y, t_vars *vars)
{
	t_point	out;

	out.x = x;
	out.y = y;
	out.z = vars->map->z_mt[y][x];
	out.color = vars->map->clrs[y][x];
	return (out);
}
