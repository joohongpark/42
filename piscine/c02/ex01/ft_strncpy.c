/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 11:39:03 by joopark           #+#    #+#             */
/*   Updated: 2020/08/06 10:47:10 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char					*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int		i;
	unsigned int		f;

	i = 0;
	f = 0;
	while (i < n)
	{
		if (f == 0)
		{
			if (src[i] != '\0')
				dest[i] = src[i];
			else
				f = 1;
		}
		if (f == 1)
			dest[i] = '\0';
		i++;
	}
	return (dest);
}
