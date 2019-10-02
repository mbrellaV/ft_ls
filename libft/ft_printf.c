/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 18:09:57 by mbrella           #+#    #+#             */
/*   Updated: 2019/10/02 18:10:00 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

void    ft_printf(const char *fmt, ...)
{
	va_list args;
	char	*type;
	int		i;
	va_start(args, fmt);

	while (*fmt)
	{
		while (*fmt && *fmt != '%')
			ft_putchar(*fmt++);
		if (*fmt == '%' && *(fmt + 1) == 'd')
		{
			i = va_arg(args, int);
			ft_putnbr(i);
			fmt += 2;
		}
		if (*fmt == '%' && *(fmt + 1) == 's')
		{
			type = va_arg(args, char*);
			ft_putstr(type);
			fmt += 2;
		}
	}
	va_end(args);
}
