/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 01:06:06 by bkiehn            #+#    #+#             */
/*   Updated: 2018/12/03 12:25:07 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*a;
	int		i;

	i = 0;
	if ((s == NULL) || (f == NULL))
		return (NULL);
	if (!(a = (char*)malloc(sizeof(char) * (ft_strlen((char*)s) + 1))))
		return (NULL);
	while (s[i] != 0)
	{
		a[i] = f(s[i]);
		i++;
	}
	a[i] = '\0';
	return (a);
}
