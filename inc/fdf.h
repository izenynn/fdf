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

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef WIN_H
#  define WIN_H 720
# endif

# ifndef WIN_W
#  define WIN_W 1280
# endif

# define LHEX "0123456789abcdef"

// structs
typedef struct s_map
{
	int	w;
	int	h;
	int	**z_mt;
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

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_map	*map;
	t_img	*img;
}	t_vars;

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

// mlx_hook.c
int		key_hook(int keycode, t_vars *vars);
int		close_win(int keycode, t_vars *vars);

// mlx_loop.c
int		update(t_vars *vars);

#endif
