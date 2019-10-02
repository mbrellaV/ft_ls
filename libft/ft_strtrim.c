/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 00:12:13 by mbrella           #+#    #+#             */
/*   Updated: 2019/09/06 11:06:49 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtrim(char const *s)
{
	char			*tmp;
	char			*dop;
	unsigned int	size;

	if (!(dop = (char *)malloc(1)))
		return (NULL);
	*dop = '\0';
	if (!s)
		return (NULL);
	size = (unsigned int)ft_strlen((char*)s);
	if (!s)
		return (NULL);
	if (size == (unsigned int)ft_count_whtsp_start(s))
		return (dop);
	tmp = NULL;
	size = size - (unsigned int)ft_count_whtsp_end(s) -
	(unsigned int)ft_count_whtsp_start(s);
	if (!s || !(tmp = ft_memalloc((size_t)size + 1)))
		return (tmp);
	if (!(tmp = ft_strncpy(tmp, s + ft_count_whtsp_start(s), size)))
		return (tmp);
	return (tmp);
}
