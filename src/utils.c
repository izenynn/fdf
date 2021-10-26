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
#include <libft/ft_printf.h>
#include <mlx.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	err_exit(const char *err, const char *msg)
{
	ft_dprintf(STDERR_FILENO, "%s: %s\n", err, msg);
	exit(EXIT_FAILURE);
}

void	perror_exit(const char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	free_split(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}

void	free_all(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_image(vars->mlx, vars->img->img);
	free_map(vars->map);
	free(vars->img);
	free(vars);
}
