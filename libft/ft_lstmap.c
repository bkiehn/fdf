/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 20:43:18 by bkiehn            #+#    #+#             */
/*   Updated: 2018/12/04 12:48:29 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(f)(t_list *elem))
{
	t_list	*new;
	t_list	*snew;
	t_list	*buf;

	if ((lst == 0) || (f == 0))
		return (NULL);
	snew = f(lst);
	buf = snew;
	lst = lst->next;
	while (lst)
	{
		new = f(lst);
		buf->next = new;
		buf = new;
		lst = lst->next;
	}
	return (snew);
}
