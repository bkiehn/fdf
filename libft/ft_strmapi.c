/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 01:27:22 by bkiehn            #+#    #+#             */
/*   Updated: 2018/11/30 01:37:11 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*a;

	i = 0;
	if ((s == NULL) || (f == NULL))
		return (NULL);
	if (!(a = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	while (s[i] != 0)
	{
		a[i] = f(i, s[i]);
		i++;
	}
	a[i] = 0;
	return (a);
}
