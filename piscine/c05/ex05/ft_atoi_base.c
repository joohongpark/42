/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 12:03:26 by joopark           #+#    #+#             */
/*   Updated: 2020/08/09 15:55:43 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int					basedigit(char *base)
{
	int				i;
	char			tmp[256];

	i = 0;
	while (i < 256)
		tmp[i++] = 0;
	i = 0;
	while (base[i] != '\0')
	{
		if (tmp[(unsigned char)base[i]] == 0)
			tmp[(unsigned char)base[i]] = 1;
		else
			return (0);
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	return (i);
}

int					isvaild(char *str, char c)
{
	int				i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int					ft_atoi_base(char *str, char *base)
{
	int				digit;
	int				sum;
	int				p;

	sum = 0;
	p = 1;
	digit = basedigit(base);
	if (digit < 2)
		return (0);
	while ((*str == '\t')
		|| (*str == '\n')
		|| (*str == '\v')
		|| (*str == '\f')
		|| (*str == '\r')
		|| (*str == ' '))
		str++;
	while (*str == '+' || *str == '-')
		p = (*str++ == '-') ? (p * -1) : p;
	while (isvaild(base, *str) > -1)
		sum = isvaild(base, *str++) + sum * digit;
	return (sum * p);
}
