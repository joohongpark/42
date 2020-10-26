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

void				ft_printer(va_list ap, t_format form)
{
	char			*c;

	form.width = (form.width == -1) ? va_arg(ap, int) : form.width;
	form.width = (form.width == -1) ? va_arg(ap, int) : form.width;
	if (form.type == '%')
		write(1, &form.type, 1);
	else if (form.type == 'd' || form.type == 'i')
		ft_putint(form, va_arg(ap, int));
	else if (form.type == 'x' || form.type == 'X' || form.type == 'u')
		ft_putuint(form, va_arg(ap, int));
	else if (form.type == 's')
	{
		c = va_arg(ap, char*);
	}
}

int					ft_putint(t_format form, int n)
{
	(void) form;
	return (ft_putnbr_fd(n, 1));
}

int					ft_putuint(t_format form, unsigned int n)
{
	(void) form;
	if (form.type == 'u')
		return (ft_putnbr_base(n, "0123456789"));
	else if (form.type == 'x')
		return (ft_putnbr_base(n, "0123456789abcdef"));
	else if (form.type == 'X')
		return (ft_putnbr_base(n, "0123456789ABCDEF"));
	return (0);
}
