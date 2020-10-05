/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 15:09:40 by joopark           #+#    #+#             */
/*   Updated: 2020/08/05 15:52:00 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char			*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char		*rtn;

	rtn = dest;
	while (*dest != '\0')
		dest++;
	while (nb-- > 0 && *src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (rtn);
}
