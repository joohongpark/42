/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 01:36:14 by joopark           #+#    #+#             */
/*   Updated: 2020/11/05 18:10:08 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_printer(va_list ap, t_format form)
{
	form.width = (form.width == -1) ? va_arg(ap, int) : form.width;
	form.set_right = (form.width < 0) ? 1 : form.set_right;
	form.width = (form.width < 0) ? ~form.width + 1 : form.width;
	form.precision = (form.precision == -1) ? va_arg(ap, int) : form.precision;
	form.precision = (form.precision < 0) ? -2 : form.precision;
	if (form.type == 'd' || form.type == 'i')
		return (ft_printint(form, va_arg(ap, int)));
	else if (form.type == 'x' || form.type == 'X' || form.type == 'u')
		return (ft_printuint(form, va_arg(ap, int)));
	else if (form.type == 'p')
		return (ft_printpointer(form, (size_t)va_arg(ap, void *)));
	else if (form.type == 's')
		return (ft_printstr(form, va_arg(ap, char*)));
	else if (form.type == 'c')
		return (ft_printchar(form, va_arg(ap, int)));
	else if (form.type == '%')
		return (ft_printchar(form, '%'));
	return (0);
}

int					ft_printstr(t_format form, char *str)
{
	int				rtn;
	int				len;

	rtn = 0;
	str = str ? str : "(null)";
	len = ft_strlen(str);
	if (form.precision < len)
		len = (form.precision == -2) ? len : form.precision;
	if (form.set_right == 0)
		rtn += ft_putchar(' ', form.width - len);
	rtn += ft_putstr(str, len);
	if (form.set_right == 1)
		rtn += ft_putchar(' ', form.width - len);
	return (rtn);
}

int					ft_printchar(t_format form, char c)
{
	int				rtn;

	rtn = 0;
	if (form.set_right == 0)
		rtn += ft_putchar(form.fill == 0 ? ' ' : '0', form.width - 1);
	rtn += ft_putchar(c, 1);
	if (form.set_right == 1)
		rtn += ft_putchar(' ', form.width - 1);
	return (rtn);
}

int					ft_printpointer(t_format form, size_t n)
{
	int				rtn;
	int				len;

	len = ft_intlen(n, 16, NULL);
	rtn = len;
	if (form.set_right == 0)
		rtn += ft_putchar(' ', form.width - (len + 2));
	rtn += write(1, "0x", 2);
	ft_putnbr_base(n, "0123456789abcdef");
	if (form.set_right == 1)
		rtn += ft_putchar(' ', form.width - (len + 2));
	return (rtn);
}
