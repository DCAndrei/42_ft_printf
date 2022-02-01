/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:39:55 by acretu            #+#    #+#             */
/*   Updated: 2021/12/16 11:08:26 by acretu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_cpy(int *dif, int *tmp, char **ret, char **s);

void	ft_width_str(char **s, t_elem *e)
{
	int		tmp;
	char	*ret;
	int		dif;

	dif = 0;
	if (e->width > ft_strlen(*s))
	{
		tmp = e->width;
		dif = tmp - ft_strlen(*s);
	}
	else
		return ;
	ret = (char *)malloc(sizeof(char) * (tmp + 1));
	if (ret == NULL)
		return ;
	ret[tmp] = '\0';
	ft_cpy(&dif, &tmp, &ret, s);
	free (*s);
	*s = ret;
}

static void	ft_cpy(int *dif, int *tmp, char **ret, char **s)
{
	int		i;
	int		j;

	i = 0;
	while (i++ < *dif)
		(*ret)[i - 1] = ' ';
	i--;
	j = 0;
	while (i++ < *tmp)
		(*ret)[i - 1] = (*s)[j++];
}
