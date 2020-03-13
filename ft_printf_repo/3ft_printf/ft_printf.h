/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuccion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 04:02:13 by dpuccion          #+#    #+#             */
/*   Updated: 2020/03/04 04:14:44 by dpuccion         ###   ########lyon.fr   */
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
void			ft_convert_di(long long nb, char *base, t_st *st);
void			ft_get_nblen(long long nb, t_st *st);
void			ft_putnbr_decimal(long long nb, char *base, t_st *st);
void			ft_putunbr_base(unsigned int nb, char *base, unsigned int blen, t_st *st);
void			ft_init_struct(t_st *st);
void			ft_what_to_do(t_st *st);
void			ft_diff1(int diff, t_st *st);
void			ft_diff2(int diff, t_st *st);
void			ft_diff3(int diff, t_st *st);
void			ft_noominus(long long nb, t_st *st);
void			ft_withminus(long long nb, char *base, t_st *st);
void			ft_parsing(const char *s, t_st *st);
void			ft_check_flags(const char *s, t_st *st);
void			ft_what_size(const char *s, t_st *st);
void			ft_what_precision(const char *s, t_st *st);
void			ft_reinit_struct(t_st *st);
int				ft_atoi(const char *str);
void			ft_write_neg0(t_st *st);
void			ft_convert_c(char c, t_st *st);
void			ft_convert_s(char *s, t_st *st);
int				ft_strlen(char *s);
void			ft_convert_u(unsigned int nb, char *base, unsigned int blen, t_st *st);
void			ft_withminusu(long long nb, char *base, unsigned int blen, t_st *st);
void			ft_convert_pc(t_st *st);
void			ft_nominuspc(t_st *st);
void			ft_convert_xx(long long nb, char *base, int blen, t_st *st);
void			ft_get_xx_len(long long nb, int blen, t_st *st);
void			ft_convert_p(char *base, unsigned int blen, t_st *st);

#endif
