/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 00:36:09 by mbrella           #+#    #+#             */
/*   Updated: 2019/09/05 18:36:02 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		size_of_int(int n)
{
	int		size;

	size = 1;
	while (n / 10)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char			*ft_itoa(int n)
{
	unsigned int	nbr;
	unsigned int	size;
	char			*tmp;
	unsigned int	i;

	if (n < 0)
		nbr = (unsigned int)(n * -1);
	else
		nbr = (unsigned int)n;
	size = (unsigned int)size_of_int(n);
	if (!(tmp = (char*)malloc(size + 1 + (n < 0 ? 1 : 0))))
		return (NULL);
	if (n < 0)
		*tmp = '-';
	i = size - 1 + (n < 0 ? 1 : 0);
	while (nbr / 10)
	{
		tmp[i] = (nbr % 10) + '0';
		i--;
		nbr = nbr / 10;
	}
	tmp[i] = (nbr % 10) + '0';
	tmp[size + (n < 0 ? 1 : 0)] = '\0';
	return (tmp);
}
