/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_flag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:35:58 by acretu            #+#    #+#             */
/*   Updated: 2021/12/12 20:22:06 by acretu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_flag(unsigned char c, t_elem *elem)
{
	int		ret;

	ret = 0;
	if (elem->width <= 0)
		ret += ft_putchar(c);
	else if (elem->dot && elem->precision == -1)
		ret += ft_putchar(c);
	else if (!elem->minus && elem->width > 0)
		ret += ft_putchar_len(' ', (elem->width - 1)) + ft_putchar(c);
	else if (elem->minus && elem->width > 0)
		ret += ft_putchar(c) + ft_putchar_len(' ', (elem->width - 1));
	return (ret);
}
