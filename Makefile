# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/09 10:16:20 by acretu            #+#    #+#              #
#    Updated: 2021/12/16 13:40:37 by acretu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= 	gcc
CFLAGS	= 	-Wall -Wextra -Werror

AR		= 	ar -rcsv
RM		= 	rm -f

NAME	= 	libftprintf.a
INCLUDE	= 	ft_printf.h

STD		= 	ft_atoi.c ft_count_dig.c ft_isconv.c ft_isdigit.c ft_printf.c \
			ft_putchar.c ft_init_struct.c ft_make_settings.c\
			ft_putstr.c ft_substr.c ft_put_dec_hex.c \
			ft_putchar_len.c ft_putchar_flag.c ft_putstr_flag.c \
			ft_width.c ft_print_flag.c ft_strlcpy.c \
			ft_putnbr_flag.c ft_putnbr.c ft_check_flags.c \
			ft_putnbr_flag2.c ft_putnbr_flag1.c ft_itoa.c \
			ft_put_dec_hex_flag.c ft_put_hex_flag2.c ft_putnbr_u_flag1.c \
			ft_itoa_hex.c ft_put_hex_flag1.c ft_itoa_u.c \
			ft_put_point.c ft_put_point_flag.c ft_put_point_flag1.c \
			ft_itoa_point.c ft_putnbr_u.c ft_putnbr_u_flag.c \
			ft_check_compatibility.c ft_check_precision.c ft_is_width.c \
			ft_strlen.c ft_copy_fn.c ft_copy_fz.c ft_prec_str.c  \
			ft_nb_is_neg.c ft_cut_sign.c ft_width_str.c


OBJ		= 	${STD:.c=.o}

all:		$(NAME)

$(NAME):	$(OBJ) $(INCLUDE)
			$(AR) $(NAME) $(OBJ)
			
bonus:		all

clean: 
			$(RM) $(OBJ) $(BON_OBJ)

fclean: 	clean
			$(RM) $(NAME)

re: 		fclean all

.PHONY: 	all clean fclean re bonus