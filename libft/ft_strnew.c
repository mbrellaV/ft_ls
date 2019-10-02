/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 22:54:04 by mbrella           #+#    #+#             */
/*   Updated: 2019/09/03 23:00:36 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	n;
	char	*tmp;

	if (!(tmp = ft_memalloc(size + 1)) || (size + 1) == 0)
		return (NULL);
	n = 0;
	while (n < size)
	{
		tmp[n] = '\0';
		n++;
	}
	return (tmp);
}
