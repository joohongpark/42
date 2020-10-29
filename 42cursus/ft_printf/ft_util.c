/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 16:51:09 by joopark           #+#    #+#             */
/*   Updated: 2020/10/29 22:58:47 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_charsearch(char c, char *chars)
{
	while (*chars)
	{
		if (*chars == c)
			return (1);
		chars++;
	}
	return (0);
}

int			ft_intlen(size_t nbr, int base, size_t *exp)
{
	size_t	l_exp;
	int		rtn;

	exp = (exp == NULL) ? &l_exp : exp;
	*exp = 1;
	rtn = 1;
	while (((*exp * base) <= nbr) && (*exp < (*exp * base)))
	{
		*exp *= base;
		rtn++;
	}
	return (rtn);
}
