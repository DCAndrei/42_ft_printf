/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_dec_hex_flag.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 09:34:09 by acretu            #+#    #+#             */
/*   Updated: 2021/12/15 19:00:22 by acretu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_dec_hex_flag(unsigned int nb, t_elem *e, int low)
{
	if (ft_check_flags(e) == 0)
		return (ft_put_dec_hex(nb, low));
	else if (ft_check_flags(e) == 1)
		return (ft_put_hex_flag1(nb, e, low));
	else if (ft_check_flags(e) == 2)
		return (ft_put_hex_flag2(nb, e, low));
	else
		return (-1);
}
