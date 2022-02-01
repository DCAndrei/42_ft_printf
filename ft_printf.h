/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 10:42:22 by acretu            #+#    #+#             */
/*   Updated: 2021/12/17 12:44:03 by acretu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# define INT_MIN -2147483648

typedef struct s_elem
{
	int		hash;
	int		zero;
	int		minus;
	int		plus;
	int		space;
	int		width;
	int		dot;
	int		precision;
	char	conv;
}				t_elem;

int		ft_printf(const char *str, ...);

/*
decision functions and uilities
*/

t_elem	ft_init_struct(void);
int		ft_make_settings(const char **str, t_elem *elem);
int		ft_check_compatibility(t_elem *elem);
int		ft_check_precision(const char **s, t_elem *elem);
int		ft_isconv(char c);
int		ft_width(const char **str);
int		ft_check_flags(t_elem *e);
int		ft_print_flag(t_elem *elem, va_list *lst);

/*
decision functions for each conversion
*/

int		ft_put_point_flag(unsigned long ptr, t_elem *e);
int		ft_putnbr_u_flag(int n, t_elem *e);
int		ft_putstr_flag(char *s, t_elem *elem);
int		ft_put_dec_hex_flag(unsigned int nb, t_elem *e, int low);
int		ft_putchar_flag(unsigned char c, t_elem *elem);
int		ft_putnbr_flag(int n, t_elem *elem);

/*
mandatory part return functions
*/

int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
int		ft_put_point(unsigned long ptr);
int		ft_putnbr_u(unsigned int n);
int		ft_put_dec_hex(unsigned int nb, int low);

/*
bonus 1 return functions
*/

int		ft_putnbr_flag1(int n, t_elem *e);
int		ft_put_point_flag1(unsigned long ptr, t_elem *e);
int		ft_putnbr_u_flag1(unsigned int n, t_elem *e);
int		ft_put_hex_flag1(unsigned int n, t_elem *e, int low);

/*
bonus 2 return functions
*/

int		ft_put_hex_flag2(unsigned int nb, t_elem *e, int low);
int		ft_putnbr_flag2(int n, t_elem *e);

/*
utility and helper functions
*/

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_atoi(char *str);
char	*ft_itoa(int n);
char	*ft_itoa_point(unsigned long nb);
char	*ft_itoa_u(unsigned int n);
char	*ft_itoa_hex(unsigned int nb, int low);
int		ft_putchar_len(char c, int max);
int		ft_isdigit(int ch);
int		ft_count_dig(int nb);
int		ft_is_width(int ch);
int		ft_strlen(char *s);
void	ft_copy_fz(char **s, char *nb_s);
char	*ft_prec_str(t_elem *e, int size, char *s_nb);
void	ft_copy_fn(char **s, char *nb_s);
void	ft_width_str(char **s, t_elem *e);
void	ft_nb_is_neg(char **s, int n);
void	ft_cut_sign(char **s);
#endif