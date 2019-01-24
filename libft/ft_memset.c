/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 18:00:08 by bkiehn            #+#    #+#             */
/*   Updated: 2018/11/24 21:38:37 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memset(void *b, int val, size_t num)
{
	int				i;
	unsigned char	*buf;

	i = 0;
	buf = (unsigned char*)b;
	while (num--)
	{
		buf[i] = (unsigned char)val;
		i++;
	}
	return (b);
}
