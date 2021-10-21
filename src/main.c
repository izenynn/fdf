/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 12:02:15 by dpoveda-          #+#    #+#             */
/*   Updated: 2021/10/20 12:02:16 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <libft/ft_fd.h>
#include <unistd.h>
#include <stdlib.h>

// TODO check norminette in libft (i added ft_convert_base from home, so maybe norminette does not like it)

int	main(int ac, char **av)
{
	t_global *tab;

	tab = initialise_tab();
	handle_args(tab, ac, av);
	free_tab(tab);
	return (0);
}
