/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 23:41:09 by mbrella           #+#    #+#             */
/*   Updated: 2019/09/05 17:33:15 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start,
		size_t len)
{
	char	*tmp;

	if (!s || !(tmp = ft_memalloc(len + 1)) || (len + 1) == 0)
		return (NULL);
	tmp = ft_strncpy(tmp, (char*)s + start, len);
	return (tmp);
}
