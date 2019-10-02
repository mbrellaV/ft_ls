/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 00:00:38 by mbrella           #+#    #+#             */
/*   Updated: 2019/09/17 16:54:33 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1,
		char const *s2)
{
	size_t	size;
	char	*tmp;

	size = 0;
	if (!s1 && !s2)
		return (NULL);
	if (s1)
		size += ft_strlen(s1);
	if (s2)
		size += ft_strlen(s2);
	if (size == 0)
		return (NULL);
	if (!(tmp = ft_memalloc(size + 1)))
		return (NULL);
	if (s1)
		tmp = ft_strcpy(tmp, (char*)s1);
	else
		tmp = ft_strcpy(tmp, (char*)s2);
	if (s1 && s2)
		tmp = ft_strcat(tmp, (char*)s2);
	tmp[size] = '\0';
	return (tmp);
}
