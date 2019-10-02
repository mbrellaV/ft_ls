/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 18:36:51 by mbrella           #+#    #+#             */
/*   Updated: 2019/09/10 15:08:07 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *d;

	d = NULL;
	while (*s)
	{
		if (*s == c)
			d = (char *)s;
		s++;
	}
	if (d)
		return (d);
	else if (c == '\0')
		return ((char *)s);
	else
		return (NULL);
}
