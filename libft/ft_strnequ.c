/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 01:52:49 by bkiehn            #+#    #+#             */
/*   Updated: 2018/11/30 02:04:06 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int i;

	i = 0;
	if ((s1 == NULL) && (s2 == NULL))
		return (1);
	if ((s1 == NULL) || (s2 == NULL))
		return (0);
	while ((n--) && ((s1 != 0) || (s2 != 0)))
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}
