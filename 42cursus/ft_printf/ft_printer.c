/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 01:36:14 by joopark           #+#    #+#             */
/*   Updated: 2020/11/09 22:16:10 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_printer(va_list ap, t_format form, int cnt)
{
	form.width = (form.width == -1) ? va_arg(ap, int) : form.width;
	form.r = (form.width < 0) ? 1 : form.r;
	form.width = (form.width < 0) ? ~form.width + 1 : form.width;
	form.prec = (form.prec == -1) ? va_arg(ap, int) : form.prec;
	form.prec = (form.prec < 0) ? -2 : form.prec;
	if (form.type == 'd' || form.type == 'i')
		return (ft_printint(form, ft_getargbysize(ap, form.length)));
	else if (form.type == 'x' || form.type == 'X' || form.type == 'u')
		return (ft_printuint(form, ft_getargbysize(ap, form.length)));
	else if (form.type == 'p')
		return (ft_printpointer(form, (size_t)va_arg(ap, void *)));
	else if (form.type == 's')
		return (ft_printstr(form, va_arg(ap, char*)));
	else if (form.type == 'c')
		return (ft_printchar(form, va_arg(ap, int)));
	else if (form.type == '%')
		return (ft_printchar(form, '%'));
	else if (form.type == 'n')
		return ((*(va_arg(ap, int *)) = cnt) < 0);
	return (0);
}

int					ft_printstr(t_format form, char *str)
{
	int				rtn;
	int				len;

	rtn = 0;
	str = str ? str : "(null)";
	len = ft_strlen(str);
	if (form.prec < len)
		len = (form.prec == -2) ? len : form.prec;
	if (form.r == 0)
		rtn += ft_putchar(' ', form.width - len);
	rtn += ft_putstr(str, len);
	if (form.r == 1)
		rtn += ft_putchar(' ', form.width - len);
	return (rtn);
}

int					ft_printchar(t_format form, char c)
{
	int				rtn;

	rtn = 0;
	if (form.r == 0)
		rtn += ft_putchar(form.fill == 0 ? ' ' : '0', form.width - 1);
	rtn += ft_putchar(c, 1);
	if (form.r == 1)
		rtn += ft_putchar(' ', form.width - 1);
	return (rtn);
}

int					ft_printpointer(t_format form, size_t n)
{
	int				rtn;
	int				len;

	len = ft_nbrlen(n, 16, NULL);
	rtn = len;
	if (form.r == 0)
		rtn += ft_putchar(' ', form.width - (len + 2));
	rtn += ft_putstr("0x", 2);
	ft_putnbr_base(n, "0123456789abcdef");
	if (form.r == 1)
		rtn += ft_putchar(' ', form.width - (len + 2));
	return (rtn);
}

ssize_t				ft_getargbysize(va_list ap, int size)
{
	ssize_t			rtn;

	rtn = 0;
	if (size == sizeof(char))
		rtn = va_arg(ap, int);
	else if (size == sizeof(short))
		rtn = va_arg(ap, int);
	else if (size == sizeof(int))
		rtn = va_arg(ap, int);
	else if (size == sizeof(long))
		rtn = va_arg(ap, long);
	else if (size == sizeof(long long))
		rtn = va_arg(ap, long long);
	return (rtn);
}