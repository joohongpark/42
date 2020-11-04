/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 01:36:14 by joopark           #+#    #+#             */
/*   Updated: 2020/11/04 21:57:32 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_printer(va_list ap, t_format form)
{
	char			c[2];

	c[1] = 0;
	form.width = (form.width == -1) ? va_arg(ap, int) : form.width;
	if (form.width < 0)
	{
		form.width = ~form.width + 1;
		form.set_right = 1;
	}
	form.precision = (form.precision == -1) ? va_arg(ap, int) : form.precision;
	form.precision = (form.precision < 0) ? -2 : form.precision;
	if (form.type == '%')
		return (write(1, &form.type, 1));
	else if (form.type == 'd' || form.type == 'i')
		return (ft_printint(form, va_arg(ap, int)));
	else if (form.type == 'x' || form.type == 'X' || form.type == 'u')
		return (ft_printuint(form, va_arg(ap, int)));
	else if (form.type == 'p')
		return (ft_printpointer(form, (size_t)va_arg(ap, void *)));
	else if (form.type == 's')
		return (ft_printstr(form, va_arg(ap, char*)));
	else if (form.type == 'c')
	{
		c[0] = va_arg(ap, int);
		return (ft_printstr(form, c));
	}
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
	int				rtn;
	int				intlen;
	int				space;
	
	intlen = ft_intlen(((n < 0) ? ~n + 1 : n) & 0x00000000ffffffffUL, 10, NULL);
	/*
	form.precision
	form.width
	부호
	0 또는 공백
	*/
	rtn = intlen;
	rtn += (n < 0) ? 1 : 0;
	space = form.width - ((form.precision > intlen) ? form.precision : intlen);
	space -= (n < 0) ? 1 : 0;
	if (form.set_right == 0 && (form.precision != -2 || form.fill == 0))
		rtn += ft_putchar(' ', space);
	if (n < 0)
		write(1, "-", 1);
	if (form.precision > intlen)
		rtn += ft_putchar('0', form.precision - intlen);
	else if (form.precision == -2 && form.set_right == 0 && form.fill == 1)
		rtn += ft_putchar('0', space);
	if (((n < 0) ? ~n + 1 : n) == 0 && form.precision == 0 && form.width == 0)
		rtn--;
	else if (((n < 0) ? ~n + 1 : n) == 0 && form.precision == 0)
		ft_putchar(' ', 1);
	else
		ft_putnbr_base(((n < 0) ? ~n + 1 : n) & 0x00000000ffffffffUL, "0123456789");
	if (form.set_right == 1)
		rtn += ft_putchar(' ', space);
	return (rtn);
}

int					ft_printuint(t_format form, size_t n)
{
	int				rtn;
	int				intlen;
	int				space;

	intlen = ft_intlen(n, (form.type == 'u') ? 10 : 16, NULL);
	rtn = intlen;
	space = form.width - ((form.precision > intlen) ? form.precision : intlen);
	if (form.set_right == 0)
		rtn += ft_putchar((form.precision == -2 && form.fill == 1) ? '0' : ' ', space);
	if (form.precision > intlen)
		rtn += ft_putchar('0', form.precision - intlen);
	if (form.type == 'u')
		ft_putnbr_base((unsigned int)n, "0123456789");
	else if (form.type == 'x')
		ft_putnbr_base((unsigned int)n, "0123456789abcdef");
	else if (form.type == 'X')
		ft_putnbr_base((unsigned int)n, "0123456789ABCDEF");
	if (form.set_right == 1)
		rtn += ft_putchar(' ', space);
	return (rtn);
}

int					ft_printpointer(t_format form, size_t n)
{
	int				rtn;
	int				len;

	len = ft_intlen(n, 16, NULL);
	rtn = len;
	if (form.set_right == 0)
		rtn += ft_putchar(' ', form.width - len);
	rtn += write(1, "0x", 2);
	ft_putnbr_base(n, "0123456789abcdef");
	if (form.set_right == 1)
		rtn += ft_putchar(' ', form.width - len);
	return (rtn);
}
