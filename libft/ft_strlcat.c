/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 18:24:38 by mbrella           #+#    #+#             */
/*   Updated: 2019/09/06 10:51:12 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	lendst;
	size_t	lensrc;

	lendst = 0;
	lensrc = 0;
	while (src[lensrc] != '\0')
		lensrc++;
	while (dst[lendst] != '\0' && lendst < size)
		lendst++;
	if (lendst == size)
		return (size + lensrc);
	if (lensrc < size - lendst)
		ft_memcpy(dst + lendst, src, lensrc + 1);
	else
	{
		ft_memcpy(dst + lendst, src, size - 1 - lendst);
		dst[size - 1] = '\0';
	}
	return (lendst + lensrc);
}
