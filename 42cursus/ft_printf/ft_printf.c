/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:48:26 by joopark           #+#    #+#             */
/*   Updated: 2020/10/24 12:29:50 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_findformat(char *str, int *cnt, va_list ap)
{
	int			tmp_char;
	int			tmp_number;
	char		*tmp_str;

	if (*(str + 1) == 'c')
	{
		tmp_char = va_arg(ap, int);
		write(1, "[char]", 6);
		return (2);
	}
	else if (*(str + 1) == 's')
	{
		tmp_str = va_arg(ap, char *);
		write(1, tmp_str, ft_strlen(tmp_str));
		*cnt += ft_strlen(tmp_str);
		return (2);
	}
	else if (*(str + 1) == 'd')
	{
		tmp_number = va_arg(ap, int);
		*cnt += ft_putnbr_fd(tmp_number, 1);
		return (2);
	}
	return (1);
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


