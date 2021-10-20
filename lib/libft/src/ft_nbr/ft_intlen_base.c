/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 14:59:23 by dpoveda-          #+#    #+#             */
/*   Updated: 2021/09/27 16:06:55 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_intlen_base(int n, int base_len)
{
	int	cnt;

	cnt = !n;
	while (n)
	{
		n /= base_len;
		cnt++;
	}
	return (cnt);
}
