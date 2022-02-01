/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_flag1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 22:58:41 by acretu            #+#    #+#             */
/*   Updated: 2021/12/16 22:56:44 by acretu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_copy_f(char **s, char *nb_s);
static void	ft_spaces_and_cpy(char **s, int *nb_space, char *nb_s);
static void	ft_check_minus(t_elem *e, char **ret, char *s_nb);
static void	ft_check_corner(t_elem *e, char **ret, int n);

int	ft_putnbr_flag1(int n, t_elem *e)
{
	char		*s_nb;
	int			size;
	char		*ret;
	int			len;

	s_nb = ft_itoa(n);
	size = ft_strlen(s_nb);
	len = 0;
	ret = ft_prec_str(e, size, s_nb);
	ft_nb_is_neg(&ret, n);
	if (n < 0)
		ft_cut_sign(&s_nb);
	ft_width_str(&ret, e);
	ft_check_minus(e, &ret, s_nb);
	ft_check_corner(e, &ret, n);
	ft_putstr(ret);
	len = ft_strlen(ret);
	free (s_nb);
	free (ret);
	return (len);
}

static void	ft_copy_f(char **s, char *nb_s)
{
	int		i;
	int		nb_space;

	nb_space = 0;
	ft_spaces_and_cpy(s, &nb_space, nb_s);
	if (nb_space)
	{
		i = 0;
		while ((*s)[nb_space + i] != '\0')
		{
			(*s)[i] = (*s)[nb_space + i];
			i++;
		}
		while ((*s)[i] != '\0')
		{
			(*s)[i] = ' ';
			i++;
		}
	}
}

static void	ft_spaces_and_cpy(char **s, int *nb_space, char *nb_s)
{
	int		len_nb;
	int		len_s;
	int		i;

	len_nb = ft_strlen(nb_s);
	len_s = ft_strlen(*s);
	while ((*s)[*nb_space] == ' ')
		(*nb_space)++;
	i = 0;
	while (i <= len_nb && nb_s[len_nb] != '-')
	{
		(*s)[len_s - i] = nb_s[len_nb - i];
		i++;
	}
}

static void	ft_check_minus(t_elem *e, char **ret, char *s_nb)
{
	int		i;

	if (e->minus)
		ft_copy_f(ret, s_nb);
	else if (e->zero && !e->dot)
	{
		i = 0;
		ft_copy_fz(ret, s_nb);
		while (i < ft_strlen(*ret))
		{
			if ((*ret)[i] == ' ')
				(*ret)[i] = '0';
			i++;
		}
	}
	else
	{
		ft_copy_fn(ret, s_nb);
	}
}

static void	ft_check_corner(t_elem *e, char **ret, int n)
{
	int		i;

	if (n == 0 && e->precision == 0)
	{
		if ((*ret)[0] == '0' && e->width < 0)
			(*ret)[0] = '\0';
		else if ((*ret)[0] == '0' && e->width)
			(*ret)[0] = ' ';
		else if (e->zero || e->minus)
		{
			i = 0;
			while ((*ret)[i] != '\0')
			{
				if ((*ret)[i] == '0')
					(*ret)[i] = ' ';
				i++;
			}
		}
	}
}
