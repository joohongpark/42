/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 16:15:46 by joopark           #+#    #+#             */
/*   Updated: 2020/08/06 14:54:05 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char				*ft_strstr(char *str, char *to_find)
{
	unsigned long	s_p;
	unsigned long	f_p;

	s_p = 0;
	f_p = 0;
	while (str[s_p] != 0)
	{
		if (str[s_p] == to_find[f_p])
			f_p++;
		else
		{
			if (to_find[f_p] == '\0')
				return (&str[s_p - f_p]);
			else
				f_p = 0;
		}
		s_p++;
	}
	return ((to_find[f_p] == '\0') ? (&str[s_p - f_p]) : (void*)0);
}
