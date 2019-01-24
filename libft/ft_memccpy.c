/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 18:00:28 by bkiehn            #+#    #+#             */
/*   Updated: 2018/11/25 20:29:08 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	int				i;
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char*)dst;
	b = (unsigned char*)src;
	i = 0;
	while (n--)
	{
		a[i] = b[i];
		if (b[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
