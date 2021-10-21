/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 13:54:38 by dpoveda-          #+#    #+#             */
/*   Updated: 2021/10/21 13:54:39 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/ft_printf.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>

void	errexit(const char *str)
{
	ft_dprintf(STDERR_FILENO, "%s: %s\n", str, strerror(errno));
	exit(EXIT_FAILURE);
}

void	free_split(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}
