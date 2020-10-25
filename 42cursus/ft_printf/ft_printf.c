/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:48:26 by joopark           #+#    #+#             */
/*   Updated: 2020/10/25 17:44:10 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_findformat(char *str, int *cnt, va_list ap)
{
	t_format	form;
	int			rtn;

	(void) ap;
	(void) cnt;
	if (*(str + 1) == '%')
	{
		write(1, str + 1, 1);
		rtn = 2;
	}
	else
	{
		rtn = ft_parser(str + 1, &form) + 2;
	}
	
	return (rtn);
}

void			ft_parsefmt(char *str, int *cnt, va_list ap)
{
	while (*str)
	{
		if (*str == '%')
		{
			str += ft_findformat(str, cnt, ap);
		}
		else
		{
			write(1, str++, 1);
			*cnt += 1;
		}
	}
}

int				ft_printf(const char *fmt, ...)
{
	va_list		ap;
	int			rtn;
	
	va_start(ap, fmt);
	rtn = 0;
	ft_parsefmt((char *)fmt, &rtn, ap);
	va_end(ap);
	return (rtn);
}


