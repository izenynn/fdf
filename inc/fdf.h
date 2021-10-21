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
	int	**mesh;
	int	**clrs;
}	t_map;

// utils.c
void		err_exit(const char *err, const char *msg);
void		perror_exit(const char *str);
void		free_split(char **split);

// tab_utils.c
void		free_map(t_map *tab);
t_map		*initialise_map(char *file);

// parse_map.c
void	handle_args(t_map **tab, int ac, char **av);

#endif
