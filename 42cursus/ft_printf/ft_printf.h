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

/* ft_printer.c */
int				ft_printer(va_list ap, t_format form, int cnt);
int				ft_printchar(t_format form, char c);
int				ft_printstr(t_format form, char *str);
int				ft_printpointer(t_format form, size_t n);
ssize_t			ft_getargbysize(va_list ap, int size);

/* ft_print_number.c */
int				ft_printint(t_format form, ssize_t n);
int				ft_printuint(t_format form, ssize_t n);

/* ft_puts.c */
int				ft_putnbr_base(size_t nbr, char *base);
int				ft_putstr(char *str, int lim);
int				ft_putchar(char c, int len);

/* ft_libft.c */
size_t			ft_strlen(char *str);
int				ft_atoi(const char *str);

/* ft_parser.c */
int				ft_parser(char *str, t_format *form);
int				ft_getnumorstar(char **str);
int				ft_getflag(char *str, t_format *form);

/* ft_util */
int				ft_charsearch(char c, char *chars);
int				ft_nbrlen(size_t nbr, int base, size_t *exp);
size_t			ft_mask(int size);

/* ft_printf.c */
int				ft_isvaild_forprintf(char *str);
void			ft_parsefmt(char *str, int *cnt, va_list ap);
int				ft_printf(const char *fmt, ...);


#endif
