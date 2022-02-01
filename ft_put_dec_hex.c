/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_dec_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 09:11:55 by acretu            #+#    #+#             */
/*   Updated: 2021/12/15 19:00:54 by acretu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put_hex(unsigned int nb, int low);
static void	hex_dig(unsigned int nb, int *len);

int	ft_put_dec_hex(unsigned int nb, int low)
{
	int		len;

	len = 0;
	if (nb < 10)
		len += ft_putchar('0' + nb);
	else
	{
		hex_dig(nb, &len);
		put_hex(nb, low);
	}
	return (len);
}

static void	put_hex(unsigned int nb, int low)
{
	unsigned int		rem;

	if (nb == 0)
		return ;
	put_hex(nb / 16, low);
	rem = nb % 16;
	if (rem < 10)
		ft_putchar('0' + rem);
	else
	{
		if (low == 1)
			ft_putchar('a' + rem - 10);
		else
			ft_putchar('A' + rem - 10);
	}
}

static void	hex_dig(unsigned int nb, int *len)
{
	if (nb == 0)
		return ;
	hex_dig(nb / 16, len);
	*len = *len + 1;
}
