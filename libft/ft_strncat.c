/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 22:23:57 by bkiehn            #+#    #+#             */
/*   Updated: 2018/12/02 16:52:15 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	ls1;

	i = 0;
	ls1 = ft_strlen(s1);
	while (n--)
	{
		s1[ls1 + i] = s2[i];
		if (s2[i] == '\0')
			return (s1);
		i++;
		if (n == 0)
			s1[ls1 + i] = 0;
	}
	return (s1);
}
