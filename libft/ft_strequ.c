/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 01:38:15 by bkiehn            #+#    #+#             */
/*   Updated: 2018/11/30 01:51:40 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int i;

	i = 0;
	if ((s1 == NULL) && (s2 == NULL))
		return (1);
	if ((s1 == NULL) || (s2 == NULL))
		return (0);
	while ((s1[i] != '\0') || (s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}
