/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:54:03 by acretu            #+#    #+#             */
/*   Updated: 2021/12/16 09:22:53 by acretu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_str_check(char **tmp, t_elem *e, char **str, int *ret);

int	ft_putstr_flag(char *s, t_elem *e)
{
	int		ret;
	char	*tmp;
	char	*str;

	ret = 0;
	str = NULL;
	if (s == NULL && e->precision == -1 && e->width == -1)
		return (ft_putstr("(null)"));
	if (s == NULL)
	{
		tmp = (char *)malloc(sizeof(char) * 7);
		if (tmp == NULL)
			return (-1);
		ft_strlcpy(tmp, "(null)", 7);
	}
	else
	{
		tmp = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (tmp == NULL)
			return (-1);
		ft_strlcpy(tmp, s, ft_strlen(s) + 1);
	}
	ft_str_check(&tmp, e, &str, &ret);
	return (ret);
}

static void	ft_str_check(char **tmp, t_elem *e, char **str, int *ret)
{
	if (e->precision == 0 && e->dot)
	{
		free (*tmp);
		*tmp = (char *)malloc(sizeof(char) * 1);
		if (*tmp == NULL)
			return ;
		(*tmp)[0] = '\0';
	}
	else if (e->dot && e->precision > 0 && e->precision < ft_strlen(*tmp))
	{
		(*str) = ft_substr(*tmp, 0, e->precision);
		free (*tmp);
		*tmp = *str;
	}
	if (e->minus && e->width > ft_strlen(*tmp))
		*ret += ft_putstr(*tmp) + ft_putchar_len(' ', (e->width - \
		ft_strlen(*tmp)));
	else if (e->minus)
		(*ret) += ft_putstr(*tmp);
	if (!e->minus && e->width > ft_strlen(*tmp))
		*ret += ft_putchar_len(' ', e->width - ft_strlen(*tmp)) + \
		ft_putstr(*tmp);
	else if (!e->minus)
		*ret += ft_putstr(*tmp);
	free (*tmp);
}
