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
	c = ft_getsign(n < 0, form.space, form.plus);
	space = form.width - ((c != '\0') + ((form.prec < l) ? l : form.prec));
	rtn = (!form.r && (!form.fill || form.prec >= 0)) ? ft_putchar(' ', space) : 0;
	rtn += (c) ? write(1, &c, 1) : 0;
	if (form.prec > l)
		rtn += ft_putchar('0', form.prec - l);
	else if ((form.width > (l + (c != '\0'))) && (form.prec == -2) && form.fill && !form.r)
		rtn += ft_putchar('0', form.width - (l + (c != '\0')));
	if (num == 0 && form.prec == 0 && form.width != 0)
		rtn += ft_putchar(' ', 1);
	else if (!(num == 0 && form.prec == 0 && form.width == 0))
		rtn += ft_putnbr_base(num & ft_mask(form.length), "0123456789");
	rtn += (form.r == 1) ? ft_putchar(' ', space) : 0;
	return (rtn);
}

int					ft_printuint(t_format form, ssize_t n)
{
	int				rtn;
	int				l;
	int				space;
	int				pre;

	l = ft_nbrlen(n & ft_mask(form.length), (form.type == 'u') ? 10 : 16, NULL);
	pre = (form.prefix && (form.type == 'X' || form.type == 'x')) ? 2 : 0;
	space = form.width - (pre + ((form.prec < l) ? l : form.prec));
	rtn = (!form.r && (!form.fill || form.prec >= 0)) ? ft_putchar(' ', space) : 0;
	rtn += (pre) ? ft_putstr(form.type == 'X' ? "0X" : "0x", 2) : 0;
	if (form.prec > l)
		rtn += ft_putchar('0', form.prec - l);
	else if ((form.width > (l + pre)) && (form.prec == -2) && form.fill && !form.r)
		rtn += ft_putchar('0', form.width - (l + pre));
	if (n == 0 && form.prec == 0)
		rtn += (form.width != 0) ? ft_putchar(' ', 1) : 0;
	else if (form.type == 'u')
		rtn += ft_putnbr_base(n & ft_mask(form.length), "0123456789");
	else if (form.type == 'x')
		rtn += ft_putnbr_base(n & ft_mask(form.length), "0123456789abcdef");
	else if (form.type == 'X')
		rtn += ft_putnbr_base(n & ft_mask(form.length), "0123456789ABCDEF");
	rtn += (form.r == 1) ? ft_putchar(' ', space) : 0;
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