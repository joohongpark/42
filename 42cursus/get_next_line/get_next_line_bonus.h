/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 19:48:08 by joopark           #+#    #+#             */
/*   Updated: 2020/10/19 19:48:09 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif
# ifndef BUFFER_SIZE
# define BUFFER_SIZE 4
# endif

void        	*ft_memcpy(void *dst, void *src, size_t n);
size_t			ft_strlen(char *str);
void			*ft_memset(void *b, int c, size_t len);
char			*ft_strnstr(const char *haystack, const char *needle, size_t len);
size_t			ft_strlcpy(char *dst, char *src, size_t dstsize);
char			*ft_strstack(char *stack, char *str);
int				get_next_line(int fd, char **line);

#endif
