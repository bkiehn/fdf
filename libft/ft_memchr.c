/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 14:35:26 by bkiehn            #+#    #+#             */
/*   Updated: 2018/11/26 17:48:52 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int				i;
	unsigned char	*a;

	a = (unsigned char*)s;
	i = 0;
	while (n--)
	{
		if (a[i] == (unsigned char)c)
			return ((void*)(a + i));
		i++;
	}
	return (NULL);
}
