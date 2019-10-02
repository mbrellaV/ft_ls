/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 01:32:44 by mbrella           #+#    #+#             */
/*   Updated: 2019/09/05 18:09:20 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int	f;

	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
		f = (unsigned int)n;
	}
	f = (unsigned int)n;
	if (f >= 10)
	{
		ft_putnbr(f / 10);
		ft_putchar(f % 10 + '0');
	}
	if (f < 10)
	{
		ft_putchar(f % 10 + '0');
	}
}
