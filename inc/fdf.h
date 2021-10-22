/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 13:17:17 by dpoveda-          #+#    #+#             */
/*   Updated: 2021/10/20 13:17:18 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define BUFFER_SIZE 10
# define LHEX "0123456789abcdef"

// structs
typedef struct s_map
{
	int	w;
	int	h;
	int	**mesh;
	int	**clrs;
}	t_map;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_l;
	int		endian;
}	t_img;


// utils.c
void		err_exit(const char *err, const char *msg);
void		perror_exit(const char *str);
void		free_split(char **split);

// tab_utils.c
void		free_map(t_map *tab);
void		alloc_map(t_map *map);
t_map		*initialise_map(char *file);

// parse_map.c
void	handle_args(t_map **map, int ac, char **av);

// mlx_main.c
int		mlx_main(t_map *map);

#endif
