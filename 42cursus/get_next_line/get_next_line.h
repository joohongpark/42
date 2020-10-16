/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 18:11:13 by joopark           #+#    #+#             */
/*   Updated: 2020/10/15 22:40:48 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

void        	*ft_memcpy(void *dst, void *src, size_t n);
size_t			ft_strlen(char *str);
void			*ft_memset(void *b, int c, size_t len);
char			*ft_strnstr(const char *haystack, const char *needle, size_t len);
size_t			ft_strlcpy(char *dst, char *src, size_t dstsize);
char			*ft_strstack(char *stack, char *str);
int				get_next_line(int fd, char **line);

#endif
