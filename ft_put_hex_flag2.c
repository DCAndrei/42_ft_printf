/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex_flag2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 09:08:04 by acretu            #+#    #+#             */
/*   Updated: 2021/12/15 19:00:07 by acretu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_hex_flag2(unsigned int nb, t_elem *e, int low)
{
	if (e->hash && nb != 0)
	{
		if (low == 1)
			return (ft_putstr("0x") + ft_put_dec_hex(nb, low));
		else
			return (ft_putstr("0X") + ft_put_dec_hex(nb, low));
	}
	else if (nb == 0)
		return (ft_putchar('0'));
	return (-1);
}
