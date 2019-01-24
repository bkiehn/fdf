/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 03:11:07 by bkiehn            #+#    #+#             */
/*   Updated: 2018/11/30 19:06:49 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static size_t	size(char const *s, size_t *start)
{
	size_t	i;
	size_t	end;
	size_t	rs;

	i = 0;
	end = 0;
	rs = ft_strlen(s);
	while (s[i] != 0)
	{
		if ((s[i] != ' ') && (s[i] != '\n') && (s[i] != '\t'))
		{
			*start = i;
			break ;
		}
		i++;
	}
	while (rs--)
		if ((s[rs] != ' ') && (s[rs] != '\n') && (s[rs] != '\t'))
		{
			end = rs;
			break ;
		}
	return (end - *start + 2);
}

char			*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	char	*a;
	size_t	k;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	k = size(s, &j);
	if ((s[j] == ' ') || (s[j] == '\n') || (s[j] == '\t'))
		k = 1;
	if (!(a = (char*)malloc(sizeof(char) * k)))
		return (NULL);
	while (--k)
	{
		a[i++] = s[j++];
	}
	a[i] = '\0';
	return (a);
}
