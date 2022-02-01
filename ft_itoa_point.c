/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_point.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 11:52:35 by acretu            #+#    #+#             */
/*   Updated: 2021/12/17 12:41:02 by acretu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	hex_dig(unsigned long nb, int *len);

char	*ft_itoa_point(unsigned long nb)
{
	int				len;
	char			*ret;
	unsigned long	rem;

	len = 2;
	if (nb < 10)
		len ++;
	else
		hex_dig(nb, &len);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (ret == NULL)
		return (NULL);
	ret[len] = '\0';
	ret[0] = '0';
	ret[1] = 'x';
	while (len-- > 2)
	{
		rem = nb % 16;
		if (rem < 10)
			ret[len] = '0' + rem;
		else
			ret[len] = 'a' + rem - 10;
		nb = nb / 16;
	}
	return (ret);
}

static void	hex_dig(unsigned long nb, int *len)
{
	if (nb == 0)
		return ;
	hex_dig(nb / 16, len);
	*len = *len + 1;
}
