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
#include <stdlib.h>

int	mlx_main(t_map *map)
{
	void	*mlx;
	t_img	*img;

	void	*mlx_win;

	mlx = mlx_init();
	img = (t_img *)malloc(sizeof(t_img));
	img->img = mlx_new_image(mlx, WIN_W, WIN_H);
	mlx_win = mlx_new_window(mlx, WIN_W, WIN_H, "fdf");
	mlx_loop(mlx);
	free(img);
	return (EXIT_SUCCESS);
}
