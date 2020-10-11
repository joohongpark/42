/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 20:23:24 by joopark           #+#    #+#             */
/*   Updated: 2020/10/11 15:36:14 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
size_t		ft_strlcpy(
	char *restrict dst, const char *restrict src, size_t dstsize)
=======
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize)
>>>>>>> 56fb8d74c582461b847b2e8b3857991fb86174b1
{
	size_t	i;
	size_t	len;

	i = 0;
	if (dst == ((char *)0) || src == ((char *)0))
		return (0);
	len = ft_strlen((char *)src);
	while ((dstsize > i + 1) && (src[i] != '\0'))
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize > 0)
		dst[i] = '\0';
	return (len);
}
