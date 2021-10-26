/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 21:05:31 by dpoveda-          #+#    #+#             */
/*   Updated: 2021/10/26 21:05:32 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static int get_light(int start, int end, double percent)
{
    return ((int)((1 - percent) * start + percent * end));
}

static int calc_color(t_point current, t_point start, t_point end,
	t_point delta)
{
	int		r;
	int		g;
	int		b;
	double	percent;

	if (current.color == end.color)
	    return (current.color);
	if (delta.x > delta.y)
	    percent = percent(start.x, end.x, current.x);
	else
	    percent = percent(start.y, end.y, current.y);
	r = get_light((start.color >> 16) & 0xFF, (end.color >> 16) & 0xFF, percent);
	g = get_light((start.color >> 8) & 0xFF, (end.color >> 8) & 0xFF, percent);
	b = get_light(start.color & 0xFF, end.color & 0xFF, percent);
	return ((r << 16) | (g << 8) | b);
}

int		get_color(t_vars *vars, t_point cur, t_point start, t_point end,
	t_point delta)
{
	int	color;

	color = calc_color(cur, s, e, delta);
	return (mlx_get_color_value(vars->mlx, vars->map->clrs[y][x]));
}
