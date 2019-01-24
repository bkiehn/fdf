/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 23:29:36 by bkiehn            #+#    #+#             */
/*   Updated: 2018/11/26 18:02:16 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int		i;
	char	*a;
	char	*b;

	a = (char*)dst;
	b = (char*)src;
	i = 0;
	while (n--)
	{
		a[i] = b[i];
		i++;
	}
	return (dst);
}
