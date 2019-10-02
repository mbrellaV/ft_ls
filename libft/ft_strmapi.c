/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 23:28:10 by mbrella           #+#    #+#             */
/*   Updated: 2019/09/05 20:47:09 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s,
		char (*f)(unsigned int, char))
{
	unsigned int	n;
	char			*tmp;

	if (!s || !(tmp = ft_memalloc((size_t)ft_strlen((char*)s) + 1))
		|| (((size_t)ft_strlen((char*)s)) + 1) == 0)
		return (NULL);
	n = 0;
	while (s[n])
	{
		tmp[n] = f(n, s[n]);
		n++;
	}
	return (tmp);
}
