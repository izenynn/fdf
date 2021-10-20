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
#include <libft/ft_printf.h>
#include <libft/ft_fd.h>
#include <libft/ft_str.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

static int	**create_map(char *parsed_map)
{
	char	**split_map;
	//int		**map;
	//int		w;
	int		h;

	split_map = ft_split(parsed_map, '\n');
	h = 0;
	while(split_map[h])
		h++;
	ft_printf("height: %d\n", h);
	return (NULL);
}

static t_map	*parse_file(char *file)
{
	t_map	*map;
	char	*line;
	char	*tmp;
	char	*parsed_map;
	int		fd;

	map = (t_map *)malloc(sizeof(map));
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_dprintf(STDERR_FILENO, "%s: %s\n", file, strerror(errno));
		exit (EXIT_FAILURE);
	}
	line = ft_get_next_line(fd);
	while (line)
	{
		tmp = ft_strjoin(parsed_map, line);
		free(parsed_map);
		parsed_map = tmp;
		line = ft_get_next_line(fd);
	}
	map->map = create_map(parsed_map);
	close(fd);
	return (map);
}

t_map	*handle_args(int ac, char **av)
{
	if (ac != 2)
	{
		ft_dprintf(STDERR_FILENO, "Invalid arguments\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	return (parse_file(av[1]));
}
