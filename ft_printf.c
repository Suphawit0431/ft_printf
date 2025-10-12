/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaensuk <ssaensuk@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 19:11:47 by ssaensuk          #+#    #+#             */
/*   Updated: 2025/10/12 22:55:19 by ssaensuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_format(const char *format, va_list argp)
{
	if (*format == 'c')
		return (ft_putchar((char)va_arg(argp, int)));
	else if (*format == 's')
		return (ft_putstr(va_arg(argp, char *)));
	else if (*format == 'p')
		return (ft_putptr((unsigned long)va_arg(argp, void *)));
	else if (*format == 'd' || *format == 'i')
		return (ft_putnbr(va_arg(argp, int)));
	else if (*format == 'u')
		return (ft_putunbr(va_arg(argp, unsigned int)));
	else if (*format == 'x' || *format == 'X')
		return (ft_puthex(va_arg(argp, unsigned int), *format));
	else if (*format == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	argp;
	int		len;

	va_start(argp, format);
	len = 0;
	while (*format)
	{
		if (*format == '%' && !(*(format + 1)))
			break ;
		else if (*format == '%')
		{
			format++;
			len += ft_check_format(format, argp);
		}
		else
			len += ft_putchar(*format);
		format++;
	}
	va_end(argp);
	return (len);
}
