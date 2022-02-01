/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prec_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 09:17:07 by acretu            #+#    #+#             */
/*   Updated: 2021/12/16 09:17:27 by acretu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_prec_str(t_elem *e, int size, char *s_nb)
{
	char		*ret;
	int			i;
	int			tmp;

	if (s_nb[0] == '-')
		size--;
	if (e->precision >= size)
		tmp = e->precision;
	else
		tmp = size;
	ret = (char *)malloc(sizeof(char) * (tmp + 1));
	if (ret == NULL)
		return (NULL);
	ret[tmp] = '\0';
	i = 0;
	while (i < tmp)
	{
		ret[i] = '0';
		i++;
	}
	return (ret);
}
