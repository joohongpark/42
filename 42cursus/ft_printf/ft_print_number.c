/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 18:08:28 by joopark           #+#    #+#             */
/*   Updated: 2020/11/10 22:02:56 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_printint(t_format form, ssize_t n)
{
	int				rtn;
	int				l;
	int				space;
	char			pre;
	ssize_t			num;

	num = (n < 0) ? ~n + 1 : n;
	l = ft_nbrlen(num & ft_mask(form.length), 10, NULL);
	l = (num == 0 && form.prec == 0) ? 0 : l;
	pre = form.space ? ' ' : '\0';
	pre = form.plus ? '+' : pre;
	pre = (n < 0) ? '-' : pre;
	space = form.width - ((pre != '\0') + ((form.prec < l) ? l : form.prec));
	rtn = (!form.r && (!form.fill || form.prec >= 0)) ? ft_putchar(' ', space) : 0;
	rtn += (pre) ? ft_putstr(&pre, 1) : 0;
	if (form.prec > l)
		rtn += ft_putchar('0', form.prec - l);
	else if ((form.width > (l + (pre != '\0'))) && (form.prec == -2) && form.fill && !form.r)
		rtn += ft_putchar('0', form.width - (l + (pre != '\0')));
	if (!(num == 0 && form.prec == 0))
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
	l = (n == 0 && form.prec == 0) ? 0 : l;
	pre = (form.prefix && ((form.type == 'X' || form.type == 'x') && n != 0)) ? 2 : 0;
	space = form.width - (pre + ((form.prec < l) ? l : form.prec));
	rtn = (!form.r && (!form.fill || form.prec >= 0)) ? ft_putchar(' ', space) : 0;
	rtn += (pre) ? ft_putstr(form.type == 'X' ? "0X" : "0x", 2) : 0;
	if (form.prec > l)
		rtn += ft_putchar('0', form.prec - l);
	else if ((form.width > (l + pre)) && (form.prec == -2) && form.fill && !form.r)
		rtn += ft_putchar('0', form.width - (l + pre));
	if (form.type == 'u' && !(n == 0 && form.prec == 0))
		rtn += ft_putnbr_base(n & ft_mask(form.length), "0123456789");
	else if (form.type == 'x' && !(n == 0 && form.prec == 0))
		rtn += ft_putnbr_base(n & ft_mask(form.length), "0123456789abcdef");
	else if (form.type == 'X' && !(n == 0 && form.prec == 0))
		rtn += ft_putnbr_base(n & ft_mask(form.length), "0123456789ABCDEF");
	rtn += (form.r == 1) ? ft_putchar(' ', space) : 0;
	return (rtn);
}
