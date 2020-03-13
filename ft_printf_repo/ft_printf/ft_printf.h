/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuccion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 10:45:19 by dpuccion          #+#    #+#             */
/*   Updated: 2020/03/11 16:30:15 by dpuccion         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

typedef struct	s_st
{
	va_list		ap;
	int			i;
	int			zero;
	int			minus;
	int			size;
	int			point;
	int			precision;
	char		type;
	int			ret;
	int			len;
}				t_st;

int				ft_printf(const char *format, ...) __attribute__((format(printf, 1, 2)));
void			ft_init_struct(t_st *st);
void			ft_reinit_struct(t_st *st);
void			ft_what_to_do(t_st *st);
void			ft_parsing(const char *s, t_st *st);
void			ft_check_flags(const char *s, t_st *st);
void			ft_what_size(const char *s, t_st *st);
void			ft_what_precision(const char *s, t_st *st);
int				ft_atoi(const char *str);
void			ft_aff_int(long long nb, char *base, int blen, t_st *st);
void			ft_get_nblen(long long nb, t_st *st);
void			ft_format(long long nb, char *base, int blen, t_st *st);
void			ft_putnbr_base(long long nb, char *base, int blen, t_st *st);
void			ft_int_format1(long long nb, t_st *st);
void			ft_int_format01(long long nb, t_st *st);
void			ft_int_formatm1(long long nb, char *base, int blen, t_st *st);
void			ft_int_format10(long long nb, t_st *st);
void			ft_int_format11(long long nb, t_st *st);
void			ft_int_format12(long long nb, t_st *st);
void			ft_int_format110(long long nb, t_st *st);
void			ft_int_format111(long long nb, t_st *st);
void			ft_int_format112(long long nb, t_st *st);
void			ft_int_format113(long long nb, t_st *st);
void			ft_int_format010(long long nb, t_st *st);
void			ft_int_format011(long long nb, t_st *st);
void			ft_int_format012(long long nb, t_st *st);
void			ft_int_format0110(long long nb, t_st *st);
void			ft_int_format0111(long long nb, t_st *st);
void			ft_int_format0112(long long nb, t_st *st);
void			ft_int_format0113(long long nb, t_st *st);
void			ft_int_formatm10(long long nb, char *base, int blen, t_st *st);
void			ft_int_formatm11(long long nb, char *base, int blen, t_st *st);
void			ft_int_formatm12(long long nb, char *base, int blen ,t_st *st);
void			ft_int_formatm110(long long nb, char *base, int blen, t_st *st);
void			ft_int_formatm111(long long nb, char *base, int blen, t_st *st);
void			ft_int_formatm112(long long nb, char *base, int blen, t_st *st);
void			ft_int_formatm113(long long nb, char *base, int blen, t_st *st);
int				ft_putchar_inc(char c, t_st *st);

#endif
