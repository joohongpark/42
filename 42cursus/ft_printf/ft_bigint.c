/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 15:15:53 by joopark           #+#    #+#             */
/*   Updated: 2020/11/11 15:45:11 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_bigint_init(int size)
{
	char	*rtn;
	int		i;

	i = 0;
	if (!(rtn = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (i <= size)
	{
		rtn[i] = '0';
		i++;
	}
	rtn[size] = '\0';
	return (rtn);
}

void		ft_bigint_divbytwo(char *c)
{
	int		i;
	int		r;
	int		m;
	int		tmp;

	m = 0;
	i = 0;
	while (c[i])
	{
		r = c[i] - '0';
		tmp = m * 10 + r;
		m = tmp % 2;
		r = tmp / 2;
		c[i] = r + '0';
		i++;
	}
}

void		ft_bigint_addint(char *s, char *t)
{
	int		i;
	int		r;
	int		m;
	int		tmp;

	m = 0;
	i = 0;
	while (s[(i + 1)])
		i++;
	while (i >= 0)
	{
		tmp = (s[i] - '0') + (t[i] - '0') + m;
		m = tmp / 10;
		r = tmp % 10;
		s[i] = r + '0';
		i--;
	}
}

void		ft_bigint_addexp(char *s, int e)
{
	char	*exp;
	int		i;

	i = 0;
	while (s[i])
		i++;
	if (!(exp = ft_bigint_init(i)) || e == 0)
		return ;
	exp[0] = '1';
	i = 0;
	while (i < e)
	{
		ft_bigint_divbytwo(exp);
		i++;
	}
	ft_bigint_addint(s, exp);
	free(exp);
}

void		ft_bigint_round(char *s, int pos)
{
	char	*tmp;
	int		i;

	i = 0;
	while (s[i])
		i++;
	if (!(tmp = ft_bigint_init(i)))
		return ;
	if (s[pos] > 4)
		tmp[pos - 1] = '1';
	ft_bigint_addint(s, tmp);
	free(tmp);
}
