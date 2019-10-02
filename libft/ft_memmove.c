/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 20:59:47 by mbrella           #+#    #+#             */
/*   Updated: 2019/09/06 11:03:20 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t					cn;
	unsigned	char		*dest;
	const unsigned char		*source;

	dest = (unsigned char*)dst;
	source = (unsigned char*)src;
	if (!dst && !src)
		return (dst);
	cn = 0;
	if (source < dest)
		while (++cn <= len)
		{
			dest[len - cn] = source[len - cn];
		}
	else
	{
		while (len-- > 0)
		{
			*dest = *source;
			dest++;
			source++;
		}
	}
	return (dst);
}
