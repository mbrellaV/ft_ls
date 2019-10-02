/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 21:51:26 by mbrella           #+#    #+#             */
/*   Updated: 2019/09/05 14:22:00 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dest;
	unsigned char	*source;

	dest = (unsigned char*)dst;
	source = (unsigned char*)src;
	while (n > 0)
	{
		*dest = *source;
		if (*dest == (unsigned char)c)
			return (dest + 1);
		source++;
		dest++;
		n--;
	}
	return (NULL);
}
