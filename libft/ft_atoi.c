/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 19:29:09 by mbrella           #+#    #+#             */
/*   Updated: 2019/09/05 20:49:36 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
int		ft_atoi(const char *str)
{
	unsigned long long	res;
	int					sign;

	res = 0;
	sign = 1;
	while (*str && (*str == ' ' || *str == '\n' ||
	*str == '\t' || *str == '\v' || *str == '\r' || *str == '\f'))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && *str >= '0' && *str <= '9')
	{
		
		res = res * 10 + (unsigned long long)(*str - '0');
		str++;
		if (res >= 9223372036854775808ULL && sign < 0)
			return (0);
		if (res >= MAXLONG)
			return (-1);
	}
	return ((int)(res * sign));
}

int main()
{
	printf("%d", ft_atoi("3222222222222222222222"));
	printf("%d", atoi("3222222222222222222222"));
}
