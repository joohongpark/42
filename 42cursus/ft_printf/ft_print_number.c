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

int					ft_printint(t_format f, ssize_t n)
{
	int				rtn;
	int				l;
	int				space;
	char			pre;
	ssize_t			num;

	num = (n < 0) ? ~n + 1 : n;
	l = ft_nbrlen(num & ft_mask(f.length), 10, NULL);
	l = (num == 0 && f.prec == 0) ? 0 : l;
	pre = f.space ? ' ' : '\0';
	pre = f.plus ? '+' : pre;
	pre = (n < 0) ? '-' : pre;
	space = f.width - ((pre != '\0') + ((f.prec < l) ? l : f.prec));
	rtn = (!f.r && (!f.fill || f.prec >= 0)) ? ft_putchar(' ', space) : 0;
	rtn += (pre) ? ft_putstr(&pre, 1) : 0;
	if (f.prec > l)
		rtn += ft_putchar('0', f.prec - l);
	else if ((f.width > (l + (!pre))) && (f.prec == -2) && f.fill && !f.r)
		rtn += ft_putchar('0', f.width - (l + (pre != '\0')));
	if (!(num == 0 && f.prec == 0))
		rtn += ft_putnbr_base(num & ft_mask(f.length), "0123456789");
	rtn += (f.r == 1) ? ft_putchar(' ', space) : 0;
	return (rtn);
}

int					ft_printuint(t_format f, ssize_t n)
{
	int				rtn;
	int				l;
	int				space;
	int				pre;
	char			*s;

	s = (f.type == 'X') ? "0X" : "0x";
	l = ft_nbrlen(n & ft_mask(f.length), (f.type == 'u') ? 10 : 16, NULL);
	l = (n == 0 && f.prec == 0) ? 0 : l;
	pre = (f.prefix && ((f.type == 'X' || f.type == 'x') && n != 0)) ? 2 : 0;
	space = f.width - (pre + ((f.prec < l) ? l : f.prec));
	rtn = (!f.r && (!f.fill || f.prec >= 0)) ? ft_putchar(' ', space) : 0;
	rtn += (pre) ? ft_putstr(s, 2) : 0;
	if (f.prec > l)
		rtn += ft_putchar('0', f.prec - l);
	else if ((f.width > (l + pre)) && (f.prec == -2) && f.fill && !f.r)
		rtn += ft_putchar('0', f.width - (l + pre));
	if (f.type == 'u' && !(n == 0 && f.prec == 0))
		rtn += ft_putnbr_base(n & ft_mask(f.length), "0123456789");
	else if (f.type == 'x' && !(n == 0 && f.prec == 0))
		rtn += ft_putnbr_base(n & ft_mask(f.length), "0123456789abcdef");
	else if (f.type == 'X' && !(n == 0 && f.prec == 0))
		rtn += ft_putnbr_base(n & ft_mask(f.length), "0123456789ABCDEF");
	rtn += (f.r == 1) ? ft_putchar(' ', space) : 0;
	return (rtn);
}
