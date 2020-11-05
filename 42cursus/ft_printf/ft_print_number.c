/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 18:08:28 by joopark           #+#    #+#             */
/*   Updated: 2020/11/05 18:10:06 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

	intlen = ft_intlen(n & 0x00000000ffffffffUL, (form.type == 'u') ? 10 : 16, NULL);
	rtn = intlen;
	space = form.width - ((form.precision > intlen) ? form.precision : intlen);
	if (form.set_right == 0)
		rtn += ft_putchar((form.precision == -2 && form.fill == 1) ? '0' : ' ', space);
	if (form.precision > intlen)
		rtn += ft_putchar('0', form.precision - intlen);
	if (n == 0 && form.precision == 0 && form.width == 0)
		rtn--;
	else if (n == 0 && form.precision == 0)
		ft_putchar(' ', 1);
	else if (form.type == 'u')
		ft_putnbr_base((unsigned int)n, "0123456789");
	else if (form.type == 'x')
		ft_putnbr_base((unsigned int)n, "0123456789abcdef");
	else if (form.type == 'X')
		ft_putnbr_base((unsigned int)n, "0123456789ABCDEF");
	if (form.set_right == 1)
		rtn += ft_putchar(' ', space);
	return (rtn);
}