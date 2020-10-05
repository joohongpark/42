/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 12:01:16 by joopark           #+#    #+#             */
/*   Updated: 2020/08/10 12:01:54 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void				btos(unsigned char byte)
{
	char			c[2];

	c[0] = (char)(byte >> 4);
	c[1] = (char)(byte & 0x0f);
	c[0] = (c[0] < 10) ? (c[0] + '0') : (c[0] - 10 + 'a');
	c[1] = (c[1] < 10) ? (c[1] + '0') : (c[1] - 10 + 'a');
	write(1, c, 2);
}

void				printaddr(void *p)
{
	int				block;

	block = sizeof(p);
	while (block != 0)
	{
		block = block - 1;
		btos((unsigned char)((unsigned long)p >> (block * 8)) & 0xff);
	}
}

void				pmax16(unsigned char *byte, int len)
{
	int				i;

	i = 0;
	while (i < 16)
	{
		if (i < len)
			btos(byte[i]);
		else
			write(1, "  ", 2);
		if (i % 2 == 1)
			write(1, " ", 1);
		i++;
	}
	i = 0;
	while (i < len)
	{
		if ((byte[i] < 32 || byte[i] > 126))
			write(1, ".", 1);
		else
			write(1, &byte[i], 1);
		i++;
	}
}

void				*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	p;
	unsigned char	*ptr;

	p = 0;
	ptr = (unsigned char *)addr;
	while (p < size)
	{
		printaddr(ptr);
		write(1, ": ", 2);
		pmax16(ptr, (size - p < 16) ? (size - p) : 16);
		p += 16;
		ptr += 16;
		write(1, "\n", 1);
	}
	return (addr);
}
