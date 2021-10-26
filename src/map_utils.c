/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 21:08:59 by dpoveda-          #+#    #+#             */
/*   Updated: 2021/10/20 21:09:00 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <libft/ft_mem.h>
#include <libft/ft_str.h>
#include <libft/ft_fd.h>
#include <stdlib.h>
#include <fcntl.h>

void	free_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	if (map->z_mt)
	{
		i = -1;
		while (++i < map->h)
		{
			if (map->z_mt[i])
				free(map->z_mt[i]);
		}
		free(map->z_mt);
	}
	if (map->clrs)
	{
		i = -1;
		while (++i < map->h)
		{
			if (map->clrs[i])
				free(map->clrs[i]);
		}
		free(map->clrs);
	}
	free(map);
}

static int	cnt_nbrs(t_map *map, char *line, char *file)
{
	int		cnt;
	char	**split;

	if (!line)
	{
		free_map(map);
		err_exit(file, "is an empty map");
	}
	split = ft_split(line, ' ');
	if (!split)
	{
		free_map(map);
		err_exit("Error", MAL_ERROR);
	}
	cnt = 0;
	while (split[cnt])
		cnt++;
	free_split(split);
	return (cnt);
}

void	alloc_map(t_map *map)
{
	int	i;

	map->z_mt = (int **)malloc(sizeof(int *) * map->h);
	map->clrs = (int **)malloc(sizeof(int *) * map->h);
	if (!map->z_mt || !map->clrs)
	{
		free_map(map);
		err_exit("Error", MAL_ERROR);
	}
	i = -1;
	while (++i < map->h)
	{
		map->z_mt[i] = (int *)malloc(sizeof(int) * map->w);
		map->clrs[i] = (int *)malloc(sizeof(int) * map->w);
		if (!map->z_mt[i] || !map->clrs[i])
		{
			free_map(map);
			err_exit("Error", MAL_ERROR);
		}
	}
}

t_map	*initialise_map(char *file)
{
	int		fd;
	t_map	*map;
	char	*line;

	map = (t_map *)ft_calloc(1, sizeof(t_map));
	if (!map)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		perror_exit(file);
	line = ft_get_next_line(fd);
	map->w = cnt_nbrs(map, line, file);
	while (line)
	{
		if (cnt_nbrs(map, line, file) != map->w && map->w != 0)
		{
			free_map(map);
			err_exit(file, "is not a valid map");
		}
		map->h++;
		free(line);
		line = ft_get_next_line(fd);
	}
	free(line);
	return (map);
}
