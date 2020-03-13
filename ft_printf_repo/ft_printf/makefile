# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpuccion <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/10 10:49:47 by dpuccion          #+#    #+#              #
#    Updated: 2020/03/11 16:17:33 by dpuccion         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME 	= 	libftprintf.a

HEADER	=	printf.h

SRCS	=	ft_aff_int.c			\
			ft_int_format.c			\
			ft_int_format011x.c		\
			ft_int_format01x.c		\
			ft_int_format11x.c		\
			ft_int_format1x.c		\
			ft_int_formatm11x.c		\
			ft_int_formatm1x.c		\
			ft_parsing.c			\
			ft_printf.c				\

OBJS	=   $(SRCS:.c=.o)

all     :   $(NAME)

$(NAME) :   $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	gcc -Wall -Werror -Wextra -c $< -o $@ -I $(HEADER)

clean   :
	/bin/rm -f $(OBJS)

fclean  :   clean
	/bin/rm -f $(NAME)

re      :   fclean all
