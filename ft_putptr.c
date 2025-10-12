/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaensuk <ssaensuk@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 02:22:19 by ssaensuk          #+#    #+#             */
/*   Updated: 2025/10/12 16:50:20 by ssaensuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned long ptr)
{
	int	len;

	len = 0;
	len += ft_putstr("0x");
	len += ft_puthex(ptr, 'x');
	return (len);
}
