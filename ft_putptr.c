/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaensuk <ssaensuk@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 02:22:19 by ssaensuk          #+#    #+#             */
/*   Updated: 2025/10/14 23:40:16 by ssaensuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthexptr(unsigned long n)
{
	int	len;

	len = 0;
	if (n >= 16)
		len += ft_puthexptr(n / 16);
	len += ft_putchar("0123456789abcdef"[n % 16]);
	return (len);
}

int	ft_putptr(unsigned long ptr)
{
	int	len;

	len = 0;
	len += ft_putstr("0x");
	len += ft_puthexptr(ptr);
	return (len);
}
