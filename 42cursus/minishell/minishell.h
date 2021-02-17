/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 01:45:40 by joopark           #+#    #+#             */
/*   Updated: 2021/02/17 13:25:46 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL_H
# define FT_MINISHELL_H

# include <libft.h>
# include <unistd.h>
# include <signal.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char			*ft_strnstack(char *stack, char *str, size_t n);
char			*ft_getbuf(ssize_t clr, char **bp);
int				ft_prechk(int fd, char **line, char **bufrtn, char **bp);
int				ft_get_next_line(int fd, char **line, char **bp);

void			ft_signal(void);
void			ft_sigint(int code);
void			ft_sigkill(int code);

pid_t			ft_exec(char *file, char *argv[], char *envp[]);

char			*ft_getline(char **bp);

#endif
