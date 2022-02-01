/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut_sign.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 11:46:35 by acretu            #+#    #+#             */
/*   Updated: 2021/12/16 11:47:05 by acretu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_cut_sign(char **s)
{
	char		*ret;
	char		len;
	int			i;

	len = ft_strlen(*s);
	ret = (char *)malloc(sizeof(char) * len);
	if (ret == NULL)
		return ;
	ret[len - 1] = '\0';
	i = 1;
	while (i < len)
	{
		ret[i - 1] = (*s)[i];
		i++;
	}
	free (*s);
	*s = ret;
}
