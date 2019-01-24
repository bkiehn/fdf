/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 23:41:14 by bkiehn            #+#    #+#             */
/*   Updated: 2018/12/02 18:40:43 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	int		j;
	int		q;
	int		slen;

	q = 0;
	i = 0;
	if (ft_strlen(needle) == 0)
		return ((char*)haystack);
	while ((haystack[i] != '\0') && (len--))
		if (haystack[i] == needle[0])
		{
			slen = ++len;
			j = i;
			while ((haystack[j] != 0) && (haystack[j++] == needle[q++])
			&& (slen--))
				if (needle[q] == 0)
					return ((char*)haystack + i);
			q = 0;
			i++;
		}
		else
			i++;
	return (NULL);
}
