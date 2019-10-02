/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 23:16:57 by mbrella           #+#    #+#             */
/*   Updated: 2019/09/06 11:01:33 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	n;
	char			*tmp;

	n = 0;
	if (!s || !(tmp = ft_memalloc((size_t)ft_strlen((char*)s) + 1))
		|| (((size_t)ft_strlen((char*)s)) + 1) == 0)
		return (NULL);
	while (s[n])
	{
		tmp[n] = f(s[n]);
		n++;
	}
	return (tmp);
}
