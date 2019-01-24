/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 19:10:05 by bkiehn            #+#    #+#             */
/*   Updated: 2018/11/27 21:02:30 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	len;
	char	*a;

	i = 0;
	a = (char*)s;
	len = ft_strlen(s) + 1;
	while (len--)
	{
		if (s[i] == (char)c)
			return (a + i);
		i++;
	}
	a = NULL;
	return (a);
}
