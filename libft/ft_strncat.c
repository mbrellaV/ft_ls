/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 18:17:19 by mbrella           #+#    #+#             */
/*   Updated: 2019/09/05 20:42:17 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	slen1;
	size_t	slen2;

	slen1 = 0;
	slen2 = 0;
	while (s1[slen1])
		slen1++;
	while (s2[slen2] && slen2 < n)
	{
		s1[slen1] = s2[slen2];
		slen1++;
		slen2++;
	}
	s1[slen1] = '\0';
	return (s1);
}
