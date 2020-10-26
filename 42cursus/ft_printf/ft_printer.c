/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 01:36:14 by joopark           #+#    #+#             */
/*   Updated: 2020/10/26 00:52:26 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printer(va_list ap, t_format form)
{
	int		i[3];
	char	*c;

	i[0] = (form.width == -1) ? va_arg(ap, int) : form.width;
	i[2] = (form.width == -1) ? va_arg(ap, int) : form.width;
	if (form.type == '%')
		write(1, &form.type, 1);
	else if (form.type == 'd')
	{
		i[1] = va_arg(ap, int);
		ft_putnbr_fd(i, 1);
	}
	else if (form.type == 's')
	{
		c = va_arg(ap, char*);
	}
}

int			ft_putnbr_fd(int n, int fd)
{
	long	tmp;
	long	base;
	char	c;
	int		rtn;

	tmp = n >= 0 ? (long)n : -1L * n;
	base = 1L;
	while ((base *= 10) < tmp)
		;
	rtn = (n < 0) ? 1 : 0;
	if (n < 0)
		write(fd, "-", 1);
	while (base /= 10)
	{
		c = (tmp / base) + '0';
		write(fd, &c, 1);
		tmp = tmp % base;
		rtn++;
	}
	return (rtn);
}
