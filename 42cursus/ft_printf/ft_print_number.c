/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 18:08:28 by joopark           #+#    #+#             */
/*   Updated: 2020/11/06 21:41:25 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_printint(t_format form, ssize_t n)
{
	int				rtn;
	int				l;
	int				space;
	char			c;
	ssize_t			num;

	num = (n < 0) ? ~n + 1 : n;
	l = ft_nbrlen(num & ft_mask(form.length), 10, NULL);	
	rtn = 0;
	c = ft_getsign(n < 0, form.space, form.plus);
	space = form.width - ((c != '\0') + ((form.prec < l) ? l : form.prec));
	if (form.r == 0 && (form.fill == 0 || form.prec >= 0))
		rtn += ft_putchar(' ', space);
	if (c)
		rtn += write(1, &c, 1);
	if (form.prec > l)
		rtn += ft_putchar('0', form.prec - l);
	else if ((form.width > (l + (c != '\0'))) && (form.prec == -2) && form.fill && !form.r)
		rtn += ft_putchar('0', form.width - (l + (c != '\0')));
	if (num == 0 && form.prec == 0 && form.width != 0)
		rtn += ft_putchar(' ', 1);
	else if (!(num == 0 && form.prec == 0 && form.width == 0))
		rtn += ft_putnbr_base(num & ft_mask(form.length), "0123456789");
	if (form.r == 1)
		rtn += ft_putchar(' ', space);
	return (rtn);
}

int					ft_printuint(t_format form, ssize_t n)
{
	int				rtn;
	int				l;
	int				space;
	
	l = ft_nbrlen(n & ft_mask(form.length), (form.type == 'u') ? 10 : 16, NULL);
	rtn = 0;
	space = form.width - ((form.prec > l) ? form.prec : l);
	if (form.r == 0)
		rtn += ft_putchar((form.prec == -2 && form.fill == 1) ? '0' : ' ', space);
	if (form.prec > l)
		rtn += ft_putchar('0', form.prec - l);
	if (n == 0 && form.prec == 0 && form.width == 0)
		rtn += 0;
	else if (n == 0 && form.prec == 0)
		rtn += ft_putchar(' ', 1);
	else if (form.type == 'u')
		rtn += ft_putnbr_base(n & ft_mask(form.length), "0123456789");
	else if (form.type == 'x')
		rtn += ft_putnbr_base(n & ft_mask(form.length), "0123456789abcdef");
	else if (form.type == 'X')
		rtn += ft_putnbr_base(n & ft_mask(form.length), "0123456789ABCDEF");
	if (form.r == 1)
		rtn += ft_putchar(' ', space);
	return (rtn);
}

char				ft_getsign(int minus, int space, int plus)
{
	char			c;

	c = space ? ' ' : '\0';
	c = plus ? '+' : c;
	c = minus ? '-' : c;
	return (c);
}