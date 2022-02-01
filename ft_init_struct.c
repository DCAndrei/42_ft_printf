/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:18:08 by acretu            #+#    #+#             */
/*   Updated: 2021/12/15 16:58:21 by acretu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_elem	ft_init_struct(void)
{
	t_elem		elem;

	elem.hash = 0;
	elem.zero = 0;
	elem.minus = 0;
	elem.plus = 0;
	elem.space = 0;
	elem.width = -1;
	elem.dot = 0;
	elem.precision = -1;
	elem.conv = '\0';
	return (elem);
}
