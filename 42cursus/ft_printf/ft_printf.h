/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:49:10 by joopark           #+#    #+#             */
/*   Updated: 2020/10/30 15:34:33 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

typedef struct	s_format
{
	int			set_right;
	int			fill;
	int			space;
	int			width;
	int			precision;
	char		type;
}				t_format;

/* ft_printer.c */
int				ft_printer(va_list ap, t_format form);
int				ft_printstr(t_format form, char *str);
int				ft_printint(t_format form, int n);
int				ft_printuint(t_format form, size_t n);
int				ft_printpointer(t_format form, size_t n);

/* ft_puts.c */
void			ft_putnbr_base(size_t nbr, char *base);
int				ft_putstr(char *str, int lim);
int				ft_putchar(char c, int len);

/* ft_libft.c */
size_t			ft_strlen(char *str);
int				ft_atoi(const char *str);

/* ft_parser.c */
int				ft_parser(char *str, t_format *form);
int				ft_getnumorstar(char *str);

/* ft_util */
int				ft_charsearch(char c, char *chars);
int				ft_intlen(size_t nbr, int base, size_t *exp);

/* ft_printf.c */
int				ft_printf(const char *fmt, ...);


#endif
