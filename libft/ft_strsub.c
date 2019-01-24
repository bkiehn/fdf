/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 02:05:05 by bkiehn            #+#    #+#             */
/*   Updated: 2018/11/30 02:36:43 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*a;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (!(a = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (len--)
		a[i++] = s[start++];
	a[i] = '\0';
	return (a);
}
