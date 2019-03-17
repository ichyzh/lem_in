/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichyzh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 16:28:10 by ichyzh            #+#    #+#             */
/*   Updated: 2018/08/08 16:28:12 by ichyzh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

t_room		*create_room(char **str, int s)
{
	t_room	*node;
	char	**l;

	node = (t_room*)malloc(sizeof(t_room));
	l = ft_strsplit(*str, ' ');
	node->name = ft_strdup(l[0]);
	node->x = ft_atoi(l[1]);
	node->y = ft_atoi(l[2]);
	node->s_e = s;
	node->pos = 0;
	node->next = NULL;
	ft_clear_arr(l);
	return (node);
}

void		check_room(t_lem **lem, char **line)
{
	t_room	*node;

	if (*line[0] == '#')
		check_start_end(lem, line);
	if (valid_room(*line, &(*lem)->room) == 1)
	{
		node = create_room(line, 0);
		ft_lst_push_back(&(*lem)->room, node);
		ft_strdel(line);
	}
	else if (*line != NULL && ft_strchr(*line, '-') == NULL)
	{
		ft_strdel(line);
		print_error(lem, 2);
	}
}

void		check_start_end(t_lem **lem, char **str)
{
	if (ft_strstr("##start", *str))
	{
		add_start_end(lem, str, 1);
		return ;
	}
	else if (ft_strstr("##end", *str))
	{
		add_start_end(lem, str, 2);
		return ;
	}
	else
		ft_strdel(str);
}

void		add_start_end(t_lem **lem, char **str, int i)
{
	t_room	*node;

	ft_strdel(str);
	get_next_line(0, str);
	if (*str)
		save_data(lem, *str);
	while (*str[0] == '#')
	{
		ft_strdel(str);
		get_next_line(0, str);
		if (*str)
			save_data(lem, *str);
	}
	if (valid_room(*str, &(*lem)->room) == 1)
	{
		node = create_room(str, i);
		ft_lst_push_back(&(*lem)->room, node);
		ft_strdel(str);
		return ;
	}
}

int			valid_room(char *str, t_room **room)
{
	int		i;
	char	**s;

	i = 0;
	if (!str)
		return (-1);
	if (!(s = ft_strsplit(str, ' ')))
		return (-1);
	while (s[i])
		i++;
	if (i != 3 || (only_number(s[1]) != 1 || (only_number(s[2]) != 1)))
	{
		ft_clear_arr(s);
		return (-1);
	}
	if ((s[0][0] == 'L') || (s[0][0] == '#') || ft_strchr(s[0], '-'))
		return (-1);
	if (find_dup_room(s, room) == -1)
		return (-1);
	ft_clear_arr(s);
	return (1);
}
