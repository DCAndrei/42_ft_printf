/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_settings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:40:17 by acretu            #+#    #+#             */
/*   Updated: 2021/12/15 19:12:34 by acretu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_flag(const char **s, t_elem *elem);
static int	ft_check_width(const char **s, t_elem *elem);
static int	ft_check_conv(const char **s, t_elem *elem);

int	ft_make_settings(const char **str, t_elem *elem)
{
	if (ft_check_flag(str, elem) == -1)
		return (-1);
	else if (ft_check_width(str, elem) == -1)
		return (-1);
	else if (ft_check_precision(str, elem) == -1)
		return (-1);
	else if (ft_check_conv(str, elem) == -1)
		return (-1);
	if (ft_check_compatibility(elem) == -1)
		return (-1);
	return (0);
}

static int	ft_check_flag(const char **s, t_elem *elem)
{
	int		error;

	error = 0;
	while (!ft_is_width(**s) && !ft_isconv(**s) && (**s != '.'))
	{
		if (**s == '#' && elem->hash == 0)
			elem->hash++;
		if (**s == '0' && elem->zero == 0 && elem->dot == 0)
			elem->zero++;
		if (**s == '-' && elem->minus == 0)
			elem->minus++;
		if (**s == '+' && elem->plus == 0)
			elem->plus++;
		if (**s == ' ' && elem->space == 0)
			elem->space++;
		(*s)++;
	}
	return (error);
}

static int	ft_check_width(const char **s, t_elem *elem)
{
	int		error;

	error = 0;
	if (ft_is_width(**s))
	{
		elem->width = ft_width(s);
		*s += ft_count_dig(elem->width);
	}
	if (!ft_isconv(**s) && !(**s == '.'))
		error = -1;
	return (error);
}

static int	ft_check_conv(const char **s, t_elem *elem)
{
	int		error;

	error = 0;
	if (ft_isconv(**s))
		elem->conv = **s;
	(*s) += 1;
	return (error);
}
