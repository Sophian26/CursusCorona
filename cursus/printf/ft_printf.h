/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberbagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:58:22 by sberbagu          #+#    #+#             */
/*   Updated: 2020/02/24 16:58:24 by sberbagu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>

# define HEXA_LOW	"0123456789abcdef"
# define HEXA_UP	"0123456789ABCDEF"
# define DEC_BASE	"0123456789"

typedef struct	s_varprintf
{
	va_list	lst;
	int		index;
	int		zero;
	int		min;
	int		precis;
	int		ispre;
	int		length;
	int		end;
	char	type;
	int		tot;
}				t_varprintf;

int				ft_printf(const char *s, ...);
void			ft_startstr(t_varprintf *str);
void			ft_restart(t_varprintf *str);
int				ft_strlen(const char *s);
int				ft_atoi(const char *nptr, t_varprintf *str);
int				ft_parsing(const char *s, t_varprintf *str);
void			ft_parsflags(const char *s, t_varprintf *str);
void			ft_parsprecis(const char *s, t_varprintf *str);
void			ft_parslength(const char *s, t_varprintf *str);
int				ft_putnbr_base(unsigned long long nbr, char *base);
void			ft_printing(t_varprintf *str);
void			ft_printuxx(t_varprintf *str);
void			ft_printcper(t_varprintf *str);
void			ft_printflags(t_varprintf *str, int cbase);
void			ft_printprec(t_varprintf *str, int cbase);
void			ft_printflagstring(t_varprintf *str, int cbase);
void			ft_printflagsmin(t_varprintf *str);
void			ft_printid(t_varprintf *str);
int				ft_countbase(long nbr, char *base);
int				ft_isdigit(int c);
int				ft_putnbr_fd(long n, int fd);
void			ft_putchar_fd(char c, int fd);
int				ft_putstr_pf(char *s, t_varprintf *str);
void			ft_printidend(t_varprintf *str, int cbase, long i);
void			ft_prints(t_varprintf *str);

#endif
