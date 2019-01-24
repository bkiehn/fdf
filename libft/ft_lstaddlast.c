/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddlast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 22:22:50 by bkiehn            #+#    #+#             */
/*   Updated: 2018/12/01 22:38:38 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstaddlast(t_list **alst, t_list *new)
{
	if ((alst != NULL) && (new != NULL))
	{
		if ((*alst)->next == 0)
			(*alst)->next = new;
		else
			while (*alst != 0)
			{
				*alst = (*alst)->next;
				if ((*alst)->next == 0)
					(*alst)->next = new;
			}
	}
}
