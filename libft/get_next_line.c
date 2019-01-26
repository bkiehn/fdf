/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <bkiehn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 13:23:09 by bkiehn            #+#    #+#             */
/*   Updated: 2019/01/26 18:54:42 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int		search(char *box)
{
	int i;

	i = 0;
	while (box[i] != 0)
		if (box[i++] == '\n')
			return (0);
	return (2);
}

static t_list	*selec(t_list **startcard, const int fd)
{
	t_list *card;

	if (*startcard == 0)
	{
		card = ft_lstnew(0, 0);
		card->content_size = (size_t)fd;
		*startcard = card;
	}
	else
		card = *startcard;
	while (card->content_size != (size_t)fd)
	{
		if (card->next == 0)
		{
			card->next = ft_lstnew(0, 0);
			card = card->next;
			card->content_size = (size_t)fd;
		}
		else
			card = card->next;
	}
	return (card);
}

static int		readfile(const int fd, t_list **card)
{
	char	buf[BUFF_SIZE + 1];
	int		ret;
	int		s;
	char	*tmp;

	s = 1;
	while ((s) && (ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (0);
		buf[ret] = 0;
		if ((*card)->content)
		{
			if (!(tmp = ft_strjoin((char*)(*card)->content, buf)))
				return (0);
			free((*card)->content);
			(*card)->content = tmp;
		}
		else if (!((*card)->content = ft_strdup(buf)))
			return (0);
		s = search(buf);
	}
	return (1);
}

static char		*clean(t_list **c)
{
	char *tmp;

	tmp = ft_strdup(ft_strchr((*c)->content, 0) + 1);
	free((*c)->content);
	(*c)->content = tmp;
	return ((*c)->content);
}

int				get_next_line(const int fd, char **line)
{
	t_list			*card;
	static	t_list	*startcard;

	if ((fd < 0) || (fd == 1) || (fd == 2))
		return (-1);
	card = selec(&startcard, fd);
	if (!(card->content) || (search((char*)card->content)))
		if (!(readfile(fd, &card)))
			return (-1);
	if ((card->content) && (ft_strchr((char*)card->content, 10)))
	{
		*(ft_strchr((char*)card->content, 10)) = 0;
		*line = ft_strdup((char*)card->content);
		card->content = clean(&card);
		return (1);
	}
	else if ((card->content) && (*((char*)card->content) != 0))
	{
		*line = ft_strdup((char*)card->content);
		free(card->content);
		card->content = 0;
		return (1);
	}
	line[0] = 0;
	return (0);
}
