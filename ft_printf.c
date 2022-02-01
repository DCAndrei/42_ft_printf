/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:11:24 by acretu            #+#    #+#             */
/*   Updated: 2021/12/17 12:35:09 by acretu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* 
On MacOs, if str == NULL, you get a segfault from printf, not -1 like in Linux
No need to pretect the function from NULL, as the test env is MacOs, and we 
need to replicate the original function!
*/

static void	ft_check(char const **str, t_elem *elem, va_list *lst, int *ret);

int	ft_printf(const char *str, ...)
{
	va_list	lst;
	int		ret_val;
	t_elem	elem;

	va_start(lst, str);
	ret_val = 0;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			ft_check(&str, &elem, &lst, &ret_val);
			if (ret_val == -1)
				return (-1);
		}
		else
		{
			ret_val += ft_putchar(*str);
			str ++;
		}
	}
	va_end(lst);
	return (ret_val);
}

static void	ft_check(char const **str, t_elem *elem, va_list *lst, int *ret)
{
	(*str)++;
	if (*(*str) == '%')
	{
		*ret += ft_putchar('%');
		(*str)++;
	}
	else
	{
		*elem = ft_init_struct();
		if (ft_make_settings(str, elem) == -1)
			*ret = -1;
		else
			*ret += ft_print_flag(elem, lst);
	}
}
