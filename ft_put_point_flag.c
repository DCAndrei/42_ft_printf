/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_point_flag.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 11:34:32 by acretu            #+#    #+#             */
/*   Updated: 2021/12/17 12:41:41 by acretu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_point_flag(unsigned long ptr, t_elem *e)
{
	if (ft_check_flags(e) == 0)
		return (ft_put_point(ptr));
	else if (ft_check_flags(e) == 1)
		return (ft_put_point_flag1(ptr, e));
	else if (ft_check_flags(e) == 2)
		return (-1);
	else
		return (-1);
}
