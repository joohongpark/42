/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 16:51:09 by joopark           #+#    #+#             */
/*   Updated: 2020/10/25 16:52:31 by joopark          ###   ########.fr       */
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