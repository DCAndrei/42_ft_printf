/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_fz.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 09:14:14 by acretu            #+#    #+#             */
/*   Updated: 2021/12/16 09:29:57 by acretu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_copy_fz(char **s, char *nb_s)
{
	int		len_nb;
	int		len_s;
	int		i;

	len_nb = ft_strlen(nb_s);
	len_s = ft_strlen(*s);
	i = 1;
	while (i <= len_nb)
	{
		(*s)[len_s - i] = nb_s[len_nb - i];
		i++;
	}
	i = 0;
	if ((*s)[0] != '-')
	{
		while (i < len_s)
		{
			if ((*s)[i] == '-')
			{
				(*s)[0] = '-';
				(*s)[i] = '0';
			}
			i++;
		}
	}
}
