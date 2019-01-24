/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 17:53:12 by bkiehn            #+#    #+#             */
/*   Updated: 2018/12/01 19:54:58 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*buf;

	if (alst != 0)
	{
		while (*alst)
		{
			buf = (**alst).next;
			del((*alst)->content, (*alst)->content_size);
			free(*alst);
			*alst = buf;
		}
	}
}
