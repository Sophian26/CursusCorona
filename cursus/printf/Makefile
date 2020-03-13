# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sberbagu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/22 18:00:58 by sberbagu          #+#    #+#              #
#    Updated: 2020/02/22 18:01:00 by sberbagu         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME    =	libftprintf.a

SRCS    =  	ft_digitprintf.c \
			ft_printf.c		\
			ft_put.c		\
			ft_parsing.c	\
			ft_charprintf.c \
			ft_printf_utils.c


HEADER	=		ft_printf.h

OBJSALL =		${SRCS:.c=.o}

%.o: %.c Makefile $(HEADER)
	    gcc -Wall -Wextra -Werror -I $(HEADER) -c $< -o $@

$(NAME) : $(HEADER) $(OBJSALL)
	    ar rcs $(NAME) $(OBJSALL)


all : $(NAME)

clean:
	    rm -f $(OBJSALL)

fclean: clean
	    rm -f  $(NAME)

re: fclean all

