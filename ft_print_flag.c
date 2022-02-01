/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:29:25 by acretu            #+#    #+#             */
/*   Updated: 2021/12/17 12:41:29 by acretu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_flag(t_elem *elem, va_list *lst)
{
	if (elem->conv == 'c')
		return (ft_putchar_flag((unsigned char)va_arg(*lst, int), elem));
	else if (elem->conv == 's')
		return (ft_putstr_flag((char *)va_arg(*lst, char *), elem));
	else if (elem->conv == 'i' || elem->conv == 'd')
		return (ft_putnbr_flag((int)va_arg(*lst, int), elem));
	else if (elem->conv == 'u')
		return (ft_putnbr_u_flag((unsigned int)va_arg(*lst, unsigned int), \
		elem));
	else if (elem->conv == 'x')
		return (ft_put_dec_hex_flag((unsigned int)va_arg(*lst, unsigned int), \
		elem, 1));
	else if (elem->conv == 'X')
		return (ft_put_dec_hex_flag((unsigned int)va_arg(*lst, unsigned int), \
		elem, 0));
	else if (elem->conv == 'p')
		return (ft_put_point_flag((unsigned long)va_arg(*lst, void *), elem));
	else
		return (0);
}
