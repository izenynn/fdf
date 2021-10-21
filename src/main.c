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

int	main(int ac, char **av)
{
	t_map *map;

	map = NULL;
	handle_args(&map, ac, av);
	free_map(map);
	return (0);
}
