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
#include <stdlib.h>

int	main(int ac, char **av)
{
	t_map	*map;

	map = NULL;
	handle_args(&map, ac, av);
	mlx_main(map);
	return (0);
}
