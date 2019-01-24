/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 02:38:05 by bkiehn            #+#    #+#             */
/*   Updated: 2018/12/01 23:05:41 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*a;
	size_t	j;

	i = 0;
	j = 0;
	if ((s1 == NULL) || (s2 == NULL))
		return (NULL);
	if (!(a = (char*)malloc(sizeof(char) *
	(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[i] != 0)
		a[j++] = s1[i++];
	i = 0;
	while (s2[i] != 0)
		a[j++] = s2[i++];
	a[j] = '\0';
	return (a);
}
