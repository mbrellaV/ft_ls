/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 22:20:03 by mbrella           #+#    #+#             */
/*   Updated: 2019/09/05 18:32:38 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned	char	*str;

	str = (unsigned char*)b;
	if (len == 0)
		return (b);
	while (len > 0)
	{
		*str = (unsigned char)c;
		str++;
		len--;
	}
	return (b);
}
