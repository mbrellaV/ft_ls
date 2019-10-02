/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 19:24:11 by mbrella           #+#    #+#             */
/*   Updated: 2019/09/05 18:07:11 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t cn;

	cn = 0;
	if (n == 0)
		return (0);
	while (*s1 == *s2 && *s1 && *s2 && cn < n - 1)
	{
		s1++;
		s2++;
		cn++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return ((int)((unsigned char)*s1 - (unsigned char)*s2));
}
