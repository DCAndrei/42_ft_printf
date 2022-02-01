/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 21:37:13 by acretu            #+#    #+#             */
/*   Updated: 2021/12/12 13:11:31 by acretu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_width(const char **str)
{
	int			len;
	char		*tmp;

	len = 0;
	tmp = (char *)*str;
	while (ft_isdigit(tmp[len]))
		len++;
	if (len == 0)
		return (0);
	if (len > 10)
		return (-1);
	else
	{
		tmp = NULL;
		tmp = ft_substr(*str, 0, len);
		len = ft_atoi(tmp);
		free (tmp);
		if (len == -1 || len > 2147483642)
			return (-1);
		return (len);
	}
}
