/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichyzh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 16:52:46 by ichyzh            #+#    #+#             */
/*   Updated: 2018/08/08 16:52:48 by ichyzh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

int			main(void)
{
	t_lem	*lem;

	init_lemin(&lem);
	if (check_ants(&lem) != 1)
		print_error(&lem, 1);
	ft_lemin(&lem);
	return (0);
}

void		ft_lemin(t_lem **lem)
{
	char *line;

	get_next_line(0, &line);
	if (line)
		save_data(lem, line);
	while (line && (!ft_strchr(line, '-') || line[0] == '#'))
	{
		check_room(lem, &line);
		if (line && !ft_strchr(line, '-'))
			free(line);
		else if (line && ft_strchr(line, '-'))
			break ;
		get_next_line(0, &line);
		if (line)
			save_data(lem, line);
	}
	(*lem)->gra = create_graph(ft_listlen(&(*lem)->room));
	if (corect_room((*lem)->room) == 0)
	{
		free(line);
		print_error(lem, 2);
	}
	check_link(&line, lem);
	work_with_path(lem);
	free(line);
}

void		work_with_path(t_lem **lem)
{
	t_ant	*temp;

	temp = NULL;
	check_path(lem);
	count_ants((*lem)->ant->ants, &(*lem)->route, NULL);
	add_route_to_ant(&(*lem)->route, NULL, &(*lem)->ant, (*lem)->ant->ants);
	write(1, (*lem)->data, ft_strlen((*lem)->data));
	write(1, "\n", 1);
	move_ant(&(*lem)->ant, temp);
}

void		ft_clear_arr(char **arr)
{
	size_t count;

	count = 0;
	while (arr[count])
	{
		free(arr[count]);
		arr[count] = NULL;
		count++;
	}
	free(arr);
	arr = NULL;
}

int			find_dup_room(char **s, t_room **room)
{
	t_room *tmp;

	tmp = *room;
	while (tmp)
	{
		if (ft_strequ(s[0], tmp->name))
		{
			ft_clear_arr(s);
			return (-1);
		}
		tmp = tmp->next;
	}
	return (1);
}
