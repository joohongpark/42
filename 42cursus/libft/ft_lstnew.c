/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 04:53:08 by joopark           #+#    #+#             */
/*   Updated: 2020/10/09 14:19:31 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list      *ft_lstnew(void *content)
{
    t_list  *rtn;

    if (!(rtn = (t_list *)malloc(sizeof(t_list))))
        return (NULL);
    rtn->content = content;
    return (rtn);
}
