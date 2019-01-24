/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 20:56:19 by bkiehn            #+#    #+#             */
/*   Updated: 2018/11/28 21:10:44 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memalloc(size_t size)
{
	char	*a;
	int		i;

	i = 0;
	if (!(a = (char*)malloc(sizeof(char) * size)))
		return (NULL);
	while (size--)
	{
		a[i] = 0;
		i++;
	}
	return ((void*)a);
}
