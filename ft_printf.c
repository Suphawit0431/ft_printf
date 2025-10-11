/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaensuk <ssaensuk@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 19:11:47 by ssaensuk          #+#    #+#             */
/*   Updated: 2025/10/11 21:05:00 by ssaensuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_format(char *format, va_list argp)
{
	int	len;

	len = 0;
	// char	test; // test variable
	
	// test
	// test = (char)va_arg(argp, int);
	
	// printf("argp_check: %c\n", test);
	if (*format == 'c')
		len += ft_putchar((char)va_arg(argp, int));
	// else if (c == 's')
	// 	len += ft_putstr(va_arg(argp, char *));
	// else if (c == 'p')
	// 	len += ft_putptr(va_arg(argp, void *));
	// else if (c == 'd')
	// 	len += ft_putnbr(va_arg(argp, int));
	// else if (c == 'i')
	// 	len += ft_putnbr(va_arg(argp, int));
	// else if (c == 'u')
	// 	len += ft_putunbr(va_arg(argp, unsigned int));
	// else if (c == 'x')
	// 	len += ft_puthex(va_arg(argp, int));
	// else if (c == 'X')
	// 	len += ft_puthex(va_arg(argp, int));
	else if (*format == '%')
		len += ft_putchar('%');
	
	return (len);
}

int ft_printf(char* format, ...)
{
    va_list argp;
	int		len;
	// char	test; // test variable
	
	va_start(argp, format);
	// test
	// test = (char)va_arg(argp, int);
	
	// printf("argp: %c\n", test);
	len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			// printf("format %c\n", *format);
			len += ft_check_format(format, argp);
		}
		else
			len += ft_putchar(*format);
		format++;
		// printf("format: %c\n", *format);
	}
	va_end(argp);
	return (len);
}

int main()
{
	int len;

	len = ft_printf("Hello %c, your score is %%", 'T');
	printf("Length: %d\n", len);
	return (0);
}