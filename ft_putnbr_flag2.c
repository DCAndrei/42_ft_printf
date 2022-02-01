/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_flag2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 09:52:56 by acretu            #+#    #+#             */
/*   Updated: 2021/12/14 10:03:36 by acretu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_flag2(int n, t_elem *e)
{
	int			ret;

	ret = 0;
	if (e->plus)
	{
		if (n >= 0)
			ret += ft_putchar('+') + ft_putnbr(n);
		else if (n == INT_MIN)
			ret += ft_putchar('-') + ft_putstr("2147483648");
		else
			ret += ft_putchar('-') + ft_putnbr(-n);
	}
	else
	{
		if (n >= 0)
			ret += ft_putchar(' ') + ft_putnbr(n);
		else if (n == INT_MIN)
			ret += ft_putchar('-') + ft_putstr("2147483648");
		else
			ret += ft_putchar('-') + ft_putnbr(-n);
	}
	return (ret);
}
