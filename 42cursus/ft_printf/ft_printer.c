/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 01:36:14 by joopark           #+#    #+#             */
/*   Updated: 2020/10/29 22:22:07 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_printer(va_list ap, t_format form)
{
	int				rtn;

	form.width = (form.width == -1) ? va_arg(ap, int) : form.width;
	form.precision = (form.precision == -1) ? va_arg(ap, int) : form.precision;
	if (form.type == '%')
		return (write(1, &form.type, 1));
	else if (form.type == 'd' || form.type == 'i')
		return (ft_printint(form, va_arg(ap, int)));
	else if (form.type == 'x' || form.type == 'X' || form.type == 'u')
		return (ft_printuint(form, va_arg(ap, int)));
	else if (form.type == 'p')
		return (ft_printuint(form, (size_t)va_arg(ap, void *)));
	else if (form.type == 's')
		return (ft_printstr(form, va_arg(ap, char*)));
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

int					ft_printint(t_format form, int n)
{
	int				len;

	len = ft_intlen(n & 0x000000007fffffffUL, 10, NULL);
	(void) form;
	if (n < 0)
		write(1, "-", 1);
	n = (n < 0) ? ~n + 1 : n;
	ft_putnbr_base(n & 0x000000007fffffffUL, "0123456789");
	return (0);
}

int					ft_printuint(t_format form, size_t n)
{
	int				rtn;
	int				len;

	len = ft_intlen(n, (form.type == 'u') ? 10 : 16, NULL);
	rtn = len;
	if (form.set_right == 0)
		rtn += ft_putchar(' ', form.width - len);
	if (form.type == 'u')
	{
		ft_putnbr_base((unsigned int)n, "0123456789");
	}
	else if (form.type == 'x')
	{
		ft_putnbr_base((unsigned int)n, "0123456789abcdef");
	}
	else if (form.type == 'X')
	{
		ft_putnbr_base((unsigned int)n, "0123456789ABCDEF");
	}
	else if (form.type == 'p')
	{
		write(1, "0x", 2);
		ft_putnbr_base(n, "0123456789abcdef");
	}
	if (form.set_right == 1)
		rtn += ft_putchar(' ', form.width - len);
	return (rtn);
}
