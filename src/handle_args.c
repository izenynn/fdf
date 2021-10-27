/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 12:02:19 by dpoveda-          #+#    #+#             */
/*   Updated: 2021/10/20 12:02:21 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <libft/ft_fd.h>
#include <libft/ft_char.h>
#include <libft/ft_str.h>
#include <libft/ft_nbr.h>
#include <libft/ft_printf.h>
#include <fcntl.h>

static void	char_tolower(char *c)
{
	*c = ft_tolower(*c);
}

static int	parse_color(t_map *map, char *s)
{
	while (*s && (ft_isdigit(*s) || *s == '-' || *s == '+' || *s == ','))
		s++;
	if (*s && *s == 'x')
	{
		map->iscolor = 1;
		ft_striter(s + 1, char_tolower);
		return (ft_atoi_base(s + 1, LHEX));
	}
	else
		return (WHITE);
	return (0);
}

static void	fill_matrix(t_map *map, int fd)
{
	int		x;
	int		y;
	char	*line;
	char	**split;

	y = -1;
	while (++y < map->h)
	{
		line = ft_get_next_line(fd);
		split = ft_split(line, ' ');
		if (!split)
		{
			free_map(map);
			err_exit("Error", MAL_ERROR);
		}
		x = -1;
		while (++x < map->w)
		{
			map->z_mt[y][x] = ft_atoi(split[x]);
			map->clrs[y][x] = parse_color(map, split[x]);
		}
		free_split(split);
		free(line);
	}
}

static void	parse_file(t_map *map, char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		free_map(map);
		perror_exit(file);
	}
	fill_matrix(map, fd);
	close(fd);
}

void	handle_args(t_map **map, int ac, char **av)
{
	char	*file;

	if (ac != 2)
		err_exit("Error", "Invalid arguments");
	ft_printf("Reading map...\n");
	file = av[1];
	*map = initialise_map(file);
	alloc_map(*map);
	parse_file(*map, file);
	get_min_max_z(*map);
}
