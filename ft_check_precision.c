/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 19:06:25 by acretu            #+#    #+#             */
/*   Updated: 2021/12/15 19:06:45 by acretu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_precision(const char **s, t_elem *elem)
{
	int		error;

	error = 0;
	if (**s == '.' && elem->dot == 0)
	{
		elem->dot++;
		(*s) += 1;
	}
	if (elem->dot && **s != '0' && !ft_is_width(**s) && !ft_isconv(**s))
		error = -1;
	if (!error && **s == '0' && elem->dot)
	{
		elem->precision = 0;
		(*s)++;
	}
	else if (!error && ft_is_width(**s) && elem->dot)
	{
		elem->precision = ft_width(s);
		*s += ft_count_dig(elem->precision);
	}
	if (!ft_isconv(**s))
		error = -1;
	return (error);
}
