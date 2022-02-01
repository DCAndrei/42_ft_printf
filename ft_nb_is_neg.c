/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_is_neg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 11:43:44 by acretu            #+#    #+#             */
/*   Updated: 2021/12/16 11:44:22 by acretu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_nb_is_neg(char **s, int n)
{
	int		i;
	char	*ret;
	int		len;

	if (n < 0)
	{
		len = ft_strlen(*s);
		ret = (char *)malloc(sizeof(char) * (len + 2));
		if (ret == NULL)
			return ;
		ret [len + 1] = '\0';
		ret[0] = '-';
		i = 1;
		while (i < len + 1)
		{
			ret[i] = (*s)[i - 1];
			i++;
		}
	}
	else
		return ;
	free (*s);
	*s = ret;
}
