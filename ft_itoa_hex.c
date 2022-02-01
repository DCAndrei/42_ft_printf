/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 10:29:19 by acretu            #+#    #+#             */
/*   Updated: 2021/12/15 17:05:35 by acretu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	hex_dig(unsigned int nb, int *len);
static void	ft_iteration(char **ret, unsigned int nb, int len, int low);

char	*ft_itoa_hex(unsigned int nb, int low)
{
	int		len;
	char	*ret;

	len = 0;
	if (nb < 10)
		len ++;
	else
		hex_dig(nb, &len);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (ret == NULL)
		return (NULL);
	ret[len] = '\0';
	ft_iteration(&ret, nb, len, low);
	return (ret);
}

static void	hex_dig(unsigned int nb, int *len)
{
	if (nb == 0)
		return ;
	hex_dig(nb / 16, len);
	*len = *len + 1;
}

static void	ft_iteration(char **ret, unsigned int nb, int len, int low)
{
	unsigned int	rem;

	while (len > 0)
	{
		rem = nb % 16;
		if (rem < 10)
			(*ret)[len - 1] = '0' + rem;
		else
		{
			if (low == 1)
				(*ret)[len - 1] = 'a' + rem - 10;
			else
				(*ret)[len - 1] = 'A' + rem - 10;
		}
		nb = nb / 16;
		len--;
	}
}
