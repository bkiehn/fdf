/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 14:52:23 by bkiehn            #+#    #+#             */
/*   Updated: 2018/12/01 17:18:57 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new;

	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content != NULL)
	{
		if (!(new->content = malloc(content_size)))
			return (NULL);
		ft_memcpy(new->content, content, content_size);
		(*new).content_size = content_size;
		(*new).next = NULL;
	}
	else
	{
		(*new).content = NULL;
		(*new).content_size = 0;
		(*new).next = NULL;
	}
	return (new);
}
