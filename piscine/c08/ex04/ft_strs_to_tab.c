/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 13:05:47 by joopark           #+#    #+#             */
/*   Updated: 2020/08/13 13:05:49 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int						ft_strlen(char *str)
{
	int					i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void					ft_strcpy(char *dest, char *src)
{
	int					i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
}

struct s_stock_str		*ft_strs_to_tab(int ac, char **av)
{
	int					i;
	struct s_stock_str	*ptr;

	i = 0;
	ptr = (struct s_stock_str *)malloc(sizeof(struct s_stock_str) * (ac + 1));
	if (ptr == (struct s_stock_str *)0)
		return ((struct s_stock_str *)0);
	while (i < ac)
	{
		ptr[i].size = ft_strlen(av[i]);
		ptr[i].str = av[i];
		if (!(ptr[i].copy = (char *)malloc(sizeof(char) * (ptr[i].size + 1))))
			return ((struct s_stock_str *)0);
		ft_strcpy(ptr[i].copy, av[i]);
		i++;
	}
	ptr[i].size = 0;
	ptr[i].str = (char *)0;
	ptr[i].copy = (char *)0;
	return (ptr);
}
