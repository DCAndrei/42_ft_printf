/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 12:21:34 by acretu            #+#    #+#             */
/*   Updated: 2021/12/15 12:34:07 by acretu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	len_nb(unsigned int n);

char	*ft_itoa_u(unsigned int n)
{
	int			len;
	char		*ret;

	ret = NULL;
	len = len_nb(n);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (ret == NULL)
		return (NULL);
	ret[len] = '\0';
	if (n == 0)
		ret[0] = '0';
	else
	{
		while (len > 0)
		{
			ret[len - 1] = '0' + (n % 10);
			len--;
			n = n / 10;
		}
	}
	return (ret);
}

static int	len_nb(unsigned int n)
{
	int		len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		len++;
		n = n / 10;
	}
	return (len);
}
