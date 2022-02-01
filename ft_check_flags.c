/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 08:39:17 by acretu            #+#    #+#             */
/*   Updated: 2021/12/15 16:58:04 by acretu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_flags(t_elem *e)
{
	int		ret;

	ret = -1;
	if (e->hash == 0 && e->minus == 0 && e->zero == 0 && e->space == 0 && \
	e->plus == 0 && e->width == -1 && e->dot == 0 && e->precision == -1)
		ret = 0;
	if ((e->hash != 0 || e->plus != 0 || e->space != 0) && \
	e->width == -1 && e->dot == 0 && e->precision == -1 && e->minus == 0 \
	&& e->zero == 0)
		ret = 2;
	if ((e->minus != 0 || e->zero != 0 || e->width != -1 || e->dot != 0 || \
	e->precision != -1) && e->hash == 0 && e->space == 0 && e->plus == 0)
		ret = 1;
	return (ret);
}
