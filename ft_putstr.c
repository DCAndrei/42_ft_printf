/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:53:02 by acretu            #+#    #+#             */
/*   Updated: 2021/12/12 16:53:16 by acretu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int		len;

	len = 0;
	if (s == NULL)
		return (ft_putstr("(null)"));
	if (s[len] == '\0')
		return (0);
	while (s[len] != '\0')
	{
		ft_putchar(s[len]);
		len++;
	}	
	return (len);
}
