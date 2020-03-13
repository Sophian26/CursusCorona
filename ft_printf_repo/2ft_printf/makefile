# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: dpuccion <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2020/01/30 12:39:50 by dpuccion     #+#   ##    ##    #+#        #
#    Updated: 2020/03/04 03:18:31 by dpuccion         ###   ########lyon.fr    #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME 	= 	libftprintf.a

HEADER	=	printf.h

SRCS	=	ft_printf.c				\
			ft_convert1.c			\
			ft_convert2.c			\
			ft_convert3.c			\
			ft_convert_nb.c			\
			ft_parsing.c			\
			ft_convert_c.c			\
			ft_convert_s.c			\
			ft_convert_u.c			\
			ft_convert_%.c			\
			ft_convert_xX.c			\
			ft_convert_p.c			\

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
