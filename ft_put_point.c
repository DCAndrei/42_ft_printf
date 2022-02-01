/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 11:32:39 by acretu            #+#    #+#             */
/*   Updated: 2021/12/17 12:42:49 by acretu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put_hex(unsigned long nb, int *len);
static int	ft_put_dec_hex_l(unsigned long nb);

int	ft_put_point(unsigned long ptr)
{
	int		len;

	len = 0;
	len += ft_putstr("0x");
	if (ptr == 0)
		len += ft_putchar('0');
	else
		len += ft_put_dec_hex_l(ptr);
	return (len);
}

static int	ft_put_dec_hex_l(unsigned long nb)
{
	int		len;

	len = 0;
	if (nb == 0)
		len += ft_putchar('0');
	else
	{
		put_hex(nb, &len);
	}
	return (len);
}

static void	put_hex(unsigned long nb, int *len)
{
	int		rem;

	if (nb == 0)
		return ;
	put_hex(nb / 16, len);
	rem = nb % 16;
	if (rem < 10)
		*len += ft_putchar('0' + rem);
	else
		*len += ft_putchar('a' + rem - 10);
}
