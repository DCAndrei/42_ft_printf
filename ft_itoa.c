/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 20:08:58 by acretu            #+#    #+#             */
/*   Updated: 2021/12/15 12:21:47 by acretu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	len_nb(int n);
static char	*put_nb(char *str, int n, int len);

char	*ft_itoa(int n)
{
	int			len;
	char		*ret;

	ret = NULL;
	len = len_nb(n);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (ret == NULL)
		return (NULL);
	ret[len] = '\0';
	len--;
	return (put_nb(ret, n, len));
}

static int	len_nb(int n)
{
	int		len;

	len = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
	{
		n = n / 10;
		n = n * (-1);
		len = len + 2;
	}
	while (n)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static char	*put_nb(char *str, int n, int len)
{
	int		stop;

	stop = 0;
	if (n == 0)
		str[0] = '0';
	else if (n < 0)
	{
		str[0] = '-';
		if ((n % 10) < 0)
			str[len] = '0' - (n % 10);
		else
			str[len] = '0' + (n % 10);
		n = n / 10;
		n = -n;
		stop++;
		len --;
	}
	while (len >= stop && n)
	{
		str[len] = '0' + (n % 10);
		len--;
		n = n / 10;
	}
	return (str);
}
