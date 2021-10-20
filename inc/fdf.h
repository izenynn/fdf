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

# define BUFFER_SIZE = 10

// structs
typedef struct s_map
{
	int	w;
	int	h;
	int	**map;
	int	**colors;
}	t_map;

typedef struct s_global
{
	t_map	*tmap;
}	t_global;

// tab_utils.c
t_global	*initialise_tab();

// parse_map.c
t_map	*handle_args(int ac, char **av);

#endif
