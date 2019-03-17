/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichyzh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 15:09:21 by ichyzh            #+#    #+#             */
/*   Updated: 2018/08/17 15:09:23 by ichyzh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void	save_data(t_lem **lem, char *line)
{
	char	*tmp;

	tmp = (*lem)->data;
	(*lem)->data = ft_strjoin(tmp, line);
	ft_strdel(&tmp);
	tmp = (*lem)->data;
	(*lem)->data = ft_strjoin(tmp, "\n");
	ft_strdel(&tmp);
}

void	drop_comments(t_lem **lem, char **line)
{
	free(*line);
	get_next_line(0, line);
	if (*line)
		save_data(lem, *line);
}

void	print_error(t_lem **lem, int i)
{
	if (i == 1)
	{
		write(1, (*lem)->data, ft_strlen((*lem)->data));
		write(1, "\n", 1);
		write(1, "You don't have ants\n", 20);
	}
	else if (i == 2)
	{
		write(1, (*lem)->data, ft_strlen((*lem)->data));
		write(1, "\n", 1);
		write(1, "Room error\n", 10);
	}
	else if (i == 3)
	{
		write(1, (*lem)->data, ft_strlen((*lem)->data));
		write(1, "\n", 1);
		write(1, "You don't have a route\n", 23);
	}
	exit(0);
}
