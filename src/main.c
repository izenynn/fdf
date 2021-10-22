/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 12:02:15 by dpoveda-          #+#    #+#             */
/*   Updated: 2021/10/20 12:02:16 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <unistd.h>
#include <stdlib.h>
#include <libft/ft_printf.h>

#include <stdio.h>

// TESTS
/*static void	print_map(t_map *map)
{
		printf("========== MESH ==========\n");
	for (int i = 0; i < map->h; i++) {
		for (int j = 0; j < map->w; j++) {
			printf("%3d ", map->mesh[i][j]);
		}
		printf("\n");
	}
	printf("========== CLRS ==========\n");
	for (int i = 0; i < map->h; i++) {
		for (int j = 0; j < map->w; j++) {
			printf("%#9x ", map->clrs[i][j]);
		}
		printf("\n");
	}
}*/
//

int	main(int ac, char **av)
{
	t_map	*map;

	map = NULL;
	handle_args(&map, ac, av);
	mlx_main(map);
	free_map(map);
	return (0);
}
