/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 16:00:04 by bkiehn            #+#    #+#             */
/*   Updated: 2018/11/28 16:14:36 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_isdigit(int c)
{
	char i;

	i = 47;
	while (i++ < 57)
		if (c == i)
			return (1);
	return (0);
}