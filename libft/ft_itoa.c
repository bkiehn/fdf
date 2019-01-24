/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 19:45:13 by bkiehn            #+#    #+#             */
/*   Updated: 2018/11/30 21:30:10 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static	int		minus(int n, int *i)
{
	if (n == -2147483648)
	{
		*i += 2;
		return (-(n % 1000000000));
	}
	else
		*i = *i + 1;
	return (-n);
}

char			*ft_itoa(int n)
{
	char	*a;
	int		i;
	int		buf;

	i = 2;
	if (n < 0)
		n = minus(n, &i);
	buf = n;
	while ((buf = (buf / 10)) > 0)
		i++;
	if (!(a = malloc(sizeof(char) * i)))
		return (0);
	a[--i] = '\0';
	a[--i] = (n % 10) + '0';
	while ((n = (n / 10)) > 0)
		a[--i] = (n % 10) + '0';
	if (i == 2)
		a[--i] = '2';
	if (i == 1)
		a[--i] = '-';
	return (a);
}
