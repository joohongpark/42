/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 09:55:50 by joopark           #+#    #+#             */
/*   Updated: 2020/08/13 09:55:57 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char				*ft_putnbr_base(int nbr, char *base);
int					basedigit(char *base);

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
	if (isvaild(base, *str) == -1)
		return (0);
	while (isvaild(base, *str) > -1)
		sum = isvaild(base, *str++) + sum * digit;
	return (sum * p);
}

char				*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int				n;
	char			*rtn;

	if ((basedigit(base_from) < 2) || (basedigit(base_to) < 2))
		return ((char *)0);
	n = ft_atoi_base(nbr, base_from);
	rtn = ft_putnbr_base(n, base_to);
	return (rtn);
}
