/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 13:20:44 by joopark           #+#    #+#             */
/*   Updated: 2020/08/13 13:20:47 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void			printstr(char *str)
{
	int			i;

	i = 0;
	while (str[i] != '\0')
		i++;
	write(1, str, i);
}

void			printnbr(int n)
{
	int			i;
	long		basecnt;
	char		c;

	basecnt = 1;
	while ((basecnt * 10) <= n)
		basecnt *= 10;
	i = 0;
	while (basecnt > 0)
	{
		c = (n / basecnt) + '0';
		write(1, &c, 1);
		n = n % basecnt;
		basecnt = basecnt / 10;
	}
}

void			ft_show_tab(struct s_stock_str *par)
{
	int			i;

	i = 0;
	while (par[i].str != (char *)0)
	{
		printstr(par[i].str);
		write(1, "\n", 1);
		printnbr(par[i].size);
		write(1, "\n", 1);
		printstr(par[i].copy);
		write(1, "\n", 1);
		i++;
	}
}
