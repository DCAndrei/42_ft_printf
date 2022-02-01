/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_compatibility.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 19:04:10 by acretu            #+#    #+#             */
/*   Updated: 2021/12/16 14:23:04 by acretu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_compatibility(t_elem *elem)
{
	if ((elem->conv == 'c' || elem->conv == 's') && elem->plus && elem->zero)
		elem->zero = 0;
	if (elem->hash && (elem->conv == 'i' || elem->conv == 'd' || \
	elem->conv == 'p' || elem->conv == 'u'))
		return (-1);
	if ((elem->plus || elem->space) && (elem->conv == 'x' || \
	elem->conv == 'X' || elem->conv == 'p' || elem->conv == 'u'))
		return (-1);
	if (elem->zero && elem->minus && (elem->conv == 'u' || elem->conv == 'p' \
	|| elem->conv == 'x' || elem->conv == 'X' || elem->conv == 'd' || \
	elem->conv == 'i'))
		elem->zero = 0;
	if ((elem->conv == 'd' || elem->conv == 'i') && elem->space && elem->plus)
		elem->space = 0;
	if (elem->dot && elem->precision == -1)
		elem->precision = 0;
	if (elem->conv == 'c' && ((elem->dot && elem->precision != -1) || \
	elem->space))
		return (-1);
	if (elem->conv == 's' && elem->dot && elem->precision == -1)
		elem->precision = 0;
	return (0);
}
