/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 22:06:50 by bkiehn            #+#    #+#             */
/*   Updated: 2018/11/29 21:30:11 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	char	*a;
	char	*b;

	i = 0;
	a = (char*)haystack;
	b = (char*)needle;
	if (ft_strlen(needle) == 0)
		return ((char*)haystack);
	while (haystack[i] != '\0')
	{
		if (haystack[i] == needle[0])
		{
			while ((*(a + i) == *b++) && (*a++ != '\0'))
				if (*b == '\0')
					return ((char*)haystack + i);
			a = (char*)haystack;
			b = (char*)needle;
		}
		i++;
	}
	a = NULL;
	return (a);
}
