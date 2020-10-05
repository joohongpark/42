/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 20:26:26 by joopark           #+#    #+#             */
/*   Updated: 2020/08/17 20:26:28 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc.h"

int				ft_atoi(char *str)
{
	int			sum;
	int			p;

	sum = 0;
	p = 1;
	while ((*str == '\t')
		|| (*str == '\n')
		|| (*str == '\v')
		|| (*str == '\f')
		|| (*str == '\r')
		|| (*str == ' '))
		str++;
	while (*str == '+' || *str == '-')
		p = (*str++ == '-') ? (p * -1) : p;
	while (*str >= '0' && *str <= '9')
		sum = (*str++ - '0') + sum * 10;
	return (sum * p);
}

int				(*ft_getop(char str))(int, int)
{
	if (str == '+')
		return (&add);
	else if (str == '-')
		return (&sub);
	else if (str == '*')
		return (&mul);
	else if (str == '/')
		return (&div);
	else if (str == '%')
		return (&mod);
	else
		return (0);
}

void			ft_printnbr(int n)
{
	int			i;
	long		basecnt;
	long		cast;
	char		c;

	cast = (n < 0) ? (n * -1L) : (n * 1L);
	basecnt = 1;
	if (n < 0)
		write(1, "-", 1);
	while ((basecnt * 10) <= n)
		basecnt *= 10;
	i = 0;
	while (basecnt > 0)
	{
		c = (cast / basecnt) + '0';
		write(1, &c, 1);
		cast = cast % basecnt;
		basecnt = basecnt / 10;
	}
}

int				main(int argc, char *argv[])
{
	int			t[2];
	int			(*func)(int, int);

	if (argc != 4)
		return (0);
	t[0] = ft_atoi(argv[1]);
	func = ft_getop(argv[2][0]);
	t[1] = ft_atoi(argv[3]);
	if ((t[1] == 0) && (func == div || func == mod))
	{
		if (func == div)
			write(1, "Stop : division by zero\n", 24);
		else if (func == mod)
			write(1, "Stop : modulo by zero\n", 22);
		return (0);
	}
	ft_printnbr((func == 0) ? 0 : (func)(t[0], t[1]));
	return (0);
}
