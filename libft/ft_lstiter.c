/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 20:17:14 by bkiehn            #+#    #+#             */
/*   Updated: 2018/12/01 20:41:29 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*buf;

	if ((lst != 0) && (f != 0))
	{
		while (lst)
		{
			buf = lst->next;
			f(lst);
			lst = buf;
		}
	}
}
