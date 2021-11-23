/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 09:23:14 by joopark           #+#    #+#             */
/*   Updated: 2021/11/23 12:35:52 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
#define UTILS_H

#include <unistd.h>

void		ft_putnbr_fd(int n, int fd);
long		ft_strlen(char *str);
int			ft_atoi(const char *str);
void		ft_putstr_fd(char *s, int fd);

#endif
