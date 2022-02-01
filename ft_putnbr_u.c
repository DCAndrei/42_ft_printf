/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 12:04:14 by acretu            #+#    #+#             */
/*   Updated: 2021/12/16 23:01:02 by acretu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_poz_nbr(unsigned int n, int *ret);

int	ft_putnbr_u(unsigned int n)
{
	char		c;
	int			ret;

	ret = 0;
	if (n == 0)
	{
		c = '0';
		write(1, &c, 1);
		return (1);
	}
	else
	{
		print_poz_nbr(n, &ret);
		return (ret);
	}
}

static	void	print_poz_nbr(unsigned int n, int *ret)
{
	char		c;

	if (n == 0)
		return ;
	print_poz_nbr(n / 10, ret);
	c = '0' + (n % 10);
	write(1, &c, 1);
	*ret += 1;
}
