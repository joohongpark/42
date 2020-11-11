/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:48:39 by joopark           #+#    #+#             */
/*   Updated: 2020/11/09 20:08:48 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_printfloat(t_format form, double f)
{
	size_t			conv;
	long			e;
	double			i;
	int				minus;

	minus = (0.0 > f) ? -1 : 1;
	conv = *((size_t*)&f) & 0x7FFFFFFFFFFFFFFF;
	f = *((double *)&conv);
	if (*((size_t *)&f) == 0xFFF0000000000000)
		return (ft_putstr("-inf", 4));
	else if (*((size_t *)&f) == 0x7FF0000000000000)
		return (ft_putstr("inf", 3));
	else if (*((size_t *)&f) == 0x7FF8000000000000)
		return (ft_putstr("nan", 3));
	ft_gete(f, &e, &i);
	ft_printe(form, f);
	//printf("{%f * %d}", i, e);
	(void) form;
	return (0);
}

int					ft_printe(t_format form, double d)
{
	int				rtn;
	int				iter;
	long			e;
	double			i;
	char			c;

	ft_gete(d, &e, &i);
	iter = 0;
	rtn = 0;
	rtn += ft_putnbr_base((long)i & ft_mask(form.length), "0123456789");
	rtn += ft_putchar('.', 1);
	while (iter < 20)
	{
		i = i * 10;
		c = '0' + (char)(((int)i) % 10);
		i = i - ((int)i/10)*10;
		write(1, &c, 1);
		iter++;
	}
	rtn += ft_putstr((e > 0) ? "e+" : "e-", 2);
	e = (e > 0) ? e : ~e + 1;
	rtn = ft_putnbr_base(e & ft_mask(form.length), "0123456789");
	return (rtn);
}

void				ft_gete(double d, long *e, double *i)
{
	*e = 0;
	*i = 0.0;
	if (d == 0.0)
		return ;
	while ((long)d >= 10 || (long)d <= 0)
	{
		*e += ((long)d >= 10) ? 1 : -1;
		d = ((long)d >= 10) ? d / 10 : d * 10;
	}
	*i = d;
}
