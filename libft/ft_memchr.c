/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 21:57:54 by mbrella           #+#    #+#             */
/*   Updated: 2019/09/05 20:47:46 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned	char	*tmp;
	unsigned	int		cn;

	tmp = (unsigned char*)s;
	cn = 0;
	while (cn < n)
	{
		if (tmp[cn] == (unsigned char)c)
			return (tmp + cn);
		cn++;
	}
	return (NULL);
}
