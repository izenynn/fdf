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
#include <libft/ft_mem.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

static void	fill_map(t_global *tab, char *parsed_map)
{
	return ;
}

static void	create_map(t_global *tab, char *parsed_map)
{
	int		i;
	char	**split_rows;
	char	**split_nbrs;

	split_rows = ft_split(parsed_map, '\n');
	tab->tmap->h = 0;
	while(split_rows[tab->tmap->h])
		tab->tmap->h++;
	tab->tmap->map = (int **)ft_calloc(1, tab->tmap->h * sizeof(int *));
	i = -1;
	while (++i < tab->tmap->h)
	{
		split_nbrs = ft_split(split_rows[i], ' ');
		tab->tmap->w = 0;
		while (split_nbrs[tab->tmap->w])
			tab->tmap->w++;
		tab->tmap->map[i] = (int *)ft_calloc(1, tab->tmap->w);
		tab->tmap->w = 0;
		while (split_nbrs[tab->tmap->w])
		{
			ft_printf("i: %d, w: %d\n", i, tab->tmap->w);
			tab->tmap->map[i][tab->tmap->w] = ft_atoi(split_nbrs[tab->tmap->w]);
			tab->tmap->w++;
		}
		free_split(split_nbrs);
	}
	free_split(split_rows);
}

static void	parse_file(t_global *tab, char *file)
{
	char	*line;
	char	*tmp;
	char	*parsed_map;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		errexit(file);
	parsed_map = ft_strdup("");
	line = ft_get_next_line(fd);
	while (line)
	{
		tmp = ft_strjoin(parsed_map, line);
		free(line);
		free(parsed_map);
		parsed_map = tmp;
		line = ft_get_next_line(fd);
	}
	free(line);
	close(fd);
	create_map(tab, parsed_map);
	free(parsed_map);
}

void	handle_args(t_global *tab, int ac, char **av)
{
	if (ac != 2)
	{
		ft_dprintf(STDERR_FILENO, "Invalid arguments\n");
		exit(EXIT_FAILURE);
	}
	parse_file(tab, av[1]);
}
