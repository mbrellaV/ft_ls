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

static	void	ft_white(int i)
{
	int d;

	d = 0;
	while (d < i)
	{
		write(1," ",1);
		d++;
	}
}

void    		ft_printf(const char *fmt, ...)
{
	va_list args;
	va_start(args, fmt);

	while (*fmt)
	{
		while (*fmt && *fmt != '%')
			ft_putchar(*fmt++);
		if (*fmt == '%' && *(fmt + 1) == 'd')
		{
			ft_putnbr(va_arg(args, int));
			fmt += 2;
		}
		if (*fmt == '%' && *(fmt + 1) == 's')
		{
			ft_putstr(va_arg(args, char*));
			fmt += 2;
		}
		if (*fmt == '%' && *(fmt + 1) == 'p')
		{
			ft_white(va_arg(args, int));
			fmt += 2;
		}
		if (*fmt == '%' && *(fmt + 1) == 'c')
		{
			ft_putchar(va_arg(args, int));
			fmt += 2;
		}
	}
	va_end(args);
}
