/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:49:10 by joopark           #+#    #+#             */
/*   Updated: 2020/10/25 18:57:58 by joopark          ###   ########.fr       */
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
void			ft_printer(va_list ap, t_format form);
int				ft_putnbr_fd(int n, int fd);

/* ft_libft.c */
size_t			ft_strlen(char *str);
int				ft_atoi(const char *str);

/* ft_parser.c */
int				ft_parser(char *str, t_format *form);
int				ft_getnumorstar(char *str);

/* ft_util */
int				ft_charsearch(char c, char *chars);

/* ft_printf.c */
int				ft_printf(const char *fmt, ...);


#endif
