/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 07:56:16 by acretu            #+#    #+#             */
/*   Updated: 2021/12/15 18:59:04 by acretu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_poz_nbr(int n, int *ret);

int	ft_putnbr(int n)
{
	char		c;
	int			i;
	int			ret;

	ret = 0;
	if (n == 0)
		return (ft_putchar('0'));
	else if (n < 0)
	{
		ret += ft_putchar('-');
		i = n % 10;
		if (i < 0)
			i = -i;
		c = '0' + i;
		n = n / 10;
		print_poz_nbr(-n, &ret);
		return (ret + ft_putchar(c));
	}
	else
	{
		print_poz_nbr(n, &ret);
		return (ret);
	}
}

static	void	print_poz_nbr(int n, int *ret)
{
	if (n == 0)
		return ;
	print_poz_nbr(n / 10, ret);
	*ret += ft_putchar('0' + (n % 10));
}
