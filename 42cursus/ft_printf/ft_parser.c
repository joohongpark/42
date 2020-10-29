/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 16:44:17 by joopark           #+#    #+#             */
/*   Updated: 2020/10/27 15:10:20 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_parser(char *str, t_format *form)
{
	char *parser;

	parser = str;
	//flag
	form->set_right = (*parser == '-') ? 1 : 0;
	parser += (*parser == '-') ? 1 : 0;
	//fill_zero
	form->fill = (*parser == '0') ? 1 : 0;
	parser += (*parser == '0') ? 1 : 0;
	//width
	form->width = ft_getnumorstar(parser);
	while (ft_charsearch(*(parser), "0123456789*"))
		parser++;
	//precision
	if (*parser == '.')
	{
		parser++;
		form->precision = ft_getnumorstar(parser);
		while (ft_charsearch(*(parser), "0123456789*"))
			parser++;
	}
	else
		form->precision = -2;
	
	//length?

	//type
	form->type = *parser;
	return (parser - str);
}

int				ft_getnumorstar(char *str)
{
	if (*str == '*')
		return (-1);
	else
		return (ft_atoi((char *)str));
}