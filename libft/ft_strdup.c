/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 19:20:42 by mbrella           #+#    #+#             */
/*   Updated: 2019/09/06 11:04:32 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*strc;
	char	*dopstr;

	if (!(strc = (char*)malloc(ft_strlen(s1) + 1))
		|| (ft_strlen(s1) + 1) == 0)
		return (NULL);
	dopstr = strc;
	while (*s1)
	{
		*strc = *s1;
		s1++;
		strc++;
	}
	*strc = '\0';
	return (dopstr);
}
