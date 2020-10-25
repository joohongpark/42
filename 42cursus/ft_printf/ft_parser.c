/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 16:44:17 by joopark           #+#    #+#             */
/*   Updated: 2020/10/25 17:59:25 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_parser(char *str, t_format *form)
{
	char *parser;

	parser = str;
	//flag
	form->set_right = (*parser == '-') ? 1 : 0;
	str += (*parser == '-') ? 1 : 0;
	//fill_zero
	form->fill = (*parser == '0') ? 1 : 0;
	str += (*parser == '0') ? 1 : 0;
	//width
	form->width = ft_atoi((char *)parser);
	while (ft_charsearch(*(parser), "0123456789"))
		parser++;
	//precision
	if (*parser == '.')
	{
		parser++;
		form->precision = ft_atoi((char *)parser);
		while (ft_charsearch(*(parser), "0123456789"))
			parser++;
	}
	else
		form->precision = 0;
	
	//length?

	//type
	form->type = *parser;
	return (str - parser);
}