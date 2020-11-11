/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:49:10 by joopark           #+#    #+#             */
/*   Updated: 2020/11/10 12:50:45 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

typedef struct	s_format
{
	int			r;
	int			fill;
	int			plus;
	int			prefix;
	int			space;
	int			width;
	int			prec;
	int			length;
	char		type;
}				t_format;

int				ft_printer(va_list ap, t_format form, int cnt);
int				ft_printchar(t_format form, char c);
int				ft_printstr(t_format form, char *str);
int				ft_printpointer(t_format f, size_t n);
ssize_t			ft_getargbysize(va_list ap, int size);
int				ft_printint(t_format f, ssize_t n);
int				ft_printuint(t_format f, ssize_t n);
int				ft_putnbr_base(size_t nbr, char *base);
int				ft_putstr(char *str, int lim);
int				ft_putchar(char c, int len);
size_t			ft_strlen(char *str);
int				ft_atoi(const char *str);
int				ft_parser(char *str, t_format *form);
int				ft_getnumorstar(char **str);
int				ft_getflag(char *str, t_format *form);
int				ft_charsearch(char c, char *chars);
int				ft_nbrlen(size_t nbr, int base, size_t *exp);
size_t			ft_mask(int size);
int				ft_isvaild_forprintf(char *str);
void			ft_parsefmt(char *str, int *cnt, va_list ap);
int				ft_printf(const char *fmt, ...);

#endif
