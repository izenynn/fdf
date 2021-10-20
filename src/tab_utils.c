/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 21:08:59 by dpoveda-          #+#    #+#             */
/*   Updated: 2021/10/20 21:09:00 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <libft/ft_mem.h>

t_global	*initialise_tab()
{
	t_global	*tab;

	tab = ft_calloc(1, sizeof(t_global));
	tab->tmap = ft_calloc(1, sizeof(t_map));
	return (tab);
}
