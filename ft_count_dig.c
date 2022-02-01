/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_dig.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 12:23:22 by acretu            #+#    #+#             */
/*   Updated: 2021/12/11 10:40:15 by acretu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_dig(int nb)
{
	int		nb_dig;

	nb_dig = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		nb_dig++;
	while (nb != 0)
	{
		nb_dig++;
		nb = nb / 10;
	}
	return (nb_dig);
}
