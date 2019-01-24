/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 20:30:52 by bkiehn            #+#    #+#             */
/*   Updated: 2018/12/04 12:47:53 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int				i;
	unsigned char	*a;
	unsigned char	*b;

	i = 0;
	if ((dst == 0) || (src == 0))
		return (0);
	a = (unsigned char*)dst;
	b = (unsigned char*)src;
	if (b < a)
		while (len)
		{
			len--;
			a[len] = b[len];
		}
	else
		while (len--)
		{
			a[i] = b[i];
			i++;
		}
	return (dst);
}
