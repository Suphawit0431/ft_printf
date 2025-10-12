/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaensuk <ssaensuk@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 22:53:37 by ssaensuk          #+#    #+#             */
/*   Updated: 2025/10/12 22:53:41 by ssaensuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, char format)
{
	int	len;

	len = 0;
	if (n >= 16)
		len += ft_puthex(n / 16, format);
	if (format == 'x')
		len += ft_putchar("0123456789abcdef"[n % 16]);
	else if (format == 'X')
		len += ft_putchar("0123456789ABCDEF"[n % 16]);
	return (len);
}
