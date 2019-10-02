/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 18:45:51 by mbrella           #+#    #+#             */
/*   Updated: 2019/09/05 20:55:44 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	unsigned int	needlecn;
	unsigned int	haycn;

	haycn = 0;
	needlecn = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (haystack[haycn])
	{
		needlecn = 0;
		while (haystack[haycn + needlecn] == needle[needlecn] &&
				needle[needlecn])
			needlecn++;
		if (needle[needlecn] == '\0')
			return ((char *)(haystack + haycn));
		haycn++;
	}
	return (NULL);
}
