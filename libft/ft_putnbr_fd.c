/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 01:56:56 by mbrella           #+#    #+#             */
/*   Updated: 2019/09/04 01:58:48 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	f;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
		f = (unsigned int)n;
	}
	f = (unsigned int)n;
	if (f >= 10)
	{
		ft_putnbr_fd(f / 10, fd);
		ft_putchar_fd(f % 10 + '0', fd);
	}
	if (f < 10)
	{
		ft_putchar_fd(n % 10 + '0', fd);
	}
}
