/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <bkiehn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 19:25:23 by dzboncak          #+#    #+#             */
/*   Updated: 2019/02/09 19:30:04 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		detect_color(t_dot **grid)
{
	t_dot	*gr;

	gr = *grid;
	while (gr)
	{
		if (gr->color != 0)
			return (1);
		gr = gr->next;
	}
	return (0);
}

int		ft_strskok(char **str)
{
	int i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

int		rfile(int fd)
{
	char	*line;
	int		h;
	int		w;
	char	**line2;
	t_dot	*grid;

	h = 0;
	grid = 0;
	get_next_line(fd, &line);
	line2 = ft_strsplit(line, ' ');
	w = ft_strskok(line2);
	write_grid(&grid, h, line2);
	h++;
	while (get_next_line(fd, &line))
	{
		line2 = ft_strsplit(line, ' ');
		if (w != ft_strskok(line2))
			return (0);
		else
			write_grid(&grid, h, line2);
		h++;
	}
	tuning(&grid, h, w);
	return (1);
}
