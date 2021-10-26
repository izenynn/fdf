/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 21:53:35 by dpoveda-          #+#    #+#             */
/*   Updated: 2021/10/26 21:53:37 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/ft_printf.h>
#include <stdlib.h>
#include <stdio.h>

void	err_exit(const char *err, const char *msg)
{
	ft_dprintf(STDERR_FILENO, "%s: %s\n", err, msg);
	exit(EXIT_FAILURE);
}

void	perror_exit(const char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}
