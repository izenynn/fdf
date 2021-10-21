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

// utils.c
void		errexit(const char *str);
void		free_split(char **split);

// tab_utils.c
void		free_tab(t_global *tab);
t_global	*initialise_tab();

// parse_map.c
void	handle_args(t_global *tab, int ac, char **av);

#endif
