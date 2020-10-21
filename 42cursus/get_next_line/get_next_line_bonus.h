/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 19:48:08 by joopark           #+#    #+#             */
/*   Updated: 2020/10/21 20:02:02 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef OPEN_MAX
#  define OPEN_MAX 10240
# endif
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

void			*ft_memcpy(void *dst, void *src, size_t n);
size_t			ft_strlen(char *str);
void			*ft_memset(void *b, int c, size_t len);
char			*ft_strnstr(char *haystack, char *needle, size_t len);
size_t			ft_strlcpy(char *dst, char *src, size_t dstsize);
char			*ft_strnstack(char *stack, char *str, size_t n);
char			*ft_getbuf(int fd, ssize_t clr);
int				ft_prechk(int fd, char **line, char **bufrtn);
int				get_next_line(int fd, char **line);

#endif
