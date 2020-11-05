/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 16:44:17 by joopark           #+#    #+#             */
/*   Updated: 2020/11/05 17:30:45 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_parser(char *str, t_format *form)
{
	char		*parser;

	parser = str;
	parser += ft_getflag(parser, form);
	form->width = ft_getnumorstar(&parser);
	form->precision = -2;
	if (*parser == '.')
	{
		parser++;
		form->precision = ft_getnumorstar(&parser);
	}
	form->length = sizeof(int);
	if (*parser == 'l' || *parser == 'h')
	{
		form->length = *parser == 'l' ? sizeof(long) : sizeof(short);
		parser++;
		if (*parser == 'l' || *parser == 'h')
		{
			form->length = *parser == 'l' ? sizeof(long long) : sizeof(char);
			parser++;
		}
	}
	form->type = *parser;
	return (parser - str);
}

int				ft_getnumorstar(char **str)
{
	int			rtn;

	rtn = -1;
	if (**str == '*')
	{
		(*str)++;
		return (rtn);
	}
	else
	{
		rtn = ft_atoi(*str);
		while (ft_charsearch(**str, "0123456789*"))
			(*str)++;
		return (rtn);
	}
}

int				ft_getflag(char *str, t_format *form)
{
	char		*parser;

	parser = str;
	form->set_right = 0;
	form->fill = 0;
	form->plus = 0;
	form->prefix = 0;
	form->space = 0;
	while (ft_charsearch(*parser, "+-# 0"))
	{
		form->set_right += (*parser == '-');
		form->fill += (*parser == '0');
		form->plus += (*parser == '+');
		form->prefix += (*parser == '#');
		form->space += (*parser == ' ');
		parser++;
	}
	return (parser - str);
}