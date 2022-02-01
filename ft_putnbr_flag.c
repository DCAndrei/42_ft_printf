/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 07:59:12 by acretu            #+#    #+#             */
/*   Updated: 2021/12/15 09:31:51 by acretu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_flag(int n, t_elem *e)
{
	if (ft_check_flags(e) == 0)
		return (ft_putnbr(n));
	else if (ft_check_flags(e) == 1)
		return (ft_putnbr_flag1(n, e));
	else if (ft_check_flags(e) == 2)
		return (ft_putnbr_flag2(n, e));
	else
		return (-1);
}
