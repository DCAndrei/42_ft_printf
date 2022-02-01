/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u_flag.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 12:05:44 by acretu            #+#    #+#             */
/*   Updated: 2021/12/15 12:19:37 by acretu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_u_flag(int n, t_elem *e)
{
	if (ft_check_flags(e) == 0)
		return (ft_putnbr_u(n));
	else if (ft_check_flags(e) == 1)
		return (ft_putnbr_u_flag1(n, e));
	else if (ft_check_flags(e) == 2)
		return (-1);
	else
		return (-1);
}
