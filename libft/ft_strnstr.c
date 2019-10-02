/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 19:13:17 by mbrella           #+#    #+#             */
/*   Updated: 2019/09/05 20:29:17 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needlecn;
	size_t	haycn;

	haycn = 0;
	needlecn = 0;
	if (!ft_strlen(needle) || !needle)
		return ((char*)haystack);
	if (len == 0)
		return (NULL);
	while (haystack[haycn] && haycn < len)
	{
		needlecn = 0;
		while (haystack[haycn + needlecn] == needle[needlecn] &&
				needle[needlecn] && (haycn + needlecn) < len)
			needlecn++;
		if (needle[needlecn] == '\0')
			return ((char *)(haystack + haycn));
		haycn++;
	}
	return (NULL);
}
