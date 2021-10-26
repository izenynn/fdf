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

# ifndef SHIFT
#  define SHIFT 10
# endif
# ifndef ROT_SHIFT
#  define ROT_SHIFT 0.25
# endif
# ifndef ZOOM_SHIFT
#  define ZOOM_SHIFT 0.5;
# endif

# define LHEX "0123456789abcdef"

# define WHITE 0xFFFFFF

# ifdef OSX
#  define KEY_ESC 53
#  define KEY_UP 126
#  define KEY_DOWN 125
#  define KEY_LEFT 123
#  define KEY_RIGHT 124
#  define KEY_W 13
#  define KEY_S 1
#  define KEY_A 0
#  define KEY_D 2
#  define KEY_Q 12
#  define KEY_E 14
#  define KEY_I 34
#  define KEY_P 35
# elif LINUX
#  define KEY_ESC 65307
#  define KEY_UP 65362
#  define KEY_DOWN 65364
#  define KEY_LEFT 65361
#  define KEY_RIGHT 65363
#  define KEY_W 119
#  define KEY_S 115
#  define KEY_A 97
#  define KEY_D 100
#  define KEY_Q 113
#  define KEY_E 101
//#  define KEY_I ?
//#  define KEY_P ?
# endif

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
	int		sz_l;
	int		endian;
}	t_img;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_map	*map;
	t_img	*img;
	int		color;
	int		shift_x;
	int		shift_y;
	float	rot;
	float	zoom;
	int		iso;
}	t_vars;

// utils.c
void		err_exit(const char *err, const char *msg);
void		perror_exit(const char *str);
void		free_split(char **split);
void		free_all(t_vars *vars);

// tab_utils.c
void		free_map(t_map *tab);
void		alloc_map(t_map *map);
t_map		*initialise_map(char *file);

// parse_map.c
void	handle_args(t_map **map, int ac, char **av);

// mlx_main.c
int		mlx_main(t_map *map);

// mlx_hook.c
int		close_win(t_vars *vars);
int		key_hook(int keycode, t_vars *vars);

// mlx_loop.c
int		update(t_vars *vars);

// draw.c
void	draw_menu(t_vars *vars);
//void	bresenham(float x, float y, float x1, float y1, t_vars *vars);
void	draw(t_vars *vars);

// draw_utils.c
int		get_color(t_vars *vars, int x, int y);
void	img_pixel_put(t_vars *vars, int x, int y);

#endif
