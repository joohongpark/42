/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 20:51:56 by joopark           #+#    #+#             */
/*   Updated: 2020/08/06 14:49:33 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int			ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int		d_p;
	unsigned int		s_p;

	d_p = 0;
	s_p = 0;
	while (dest[d_p] != '\0')
		d_p++;
	while (src[s_p] != '\0' && --size > 0)
	{
		dest[d_p] = src[s_p];
		s_p++;
		d_p++;
	}
	dest[d_p] = '\0';
	return (d_p);
}
