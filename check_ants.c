/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichyzh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 16:27:39 by ichyzh            #+#    #+#             */
/*   Updated: 2018/08/08 16:27:42 by ichyzh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

int			check_ants(t_lem **lem)
{
	char	*line;

	line = NULL;
	get_next_line(0, &line);
	if (!line)
		return (-1);
	save_data(lem, line);
	while (line[0] == '#')
		drop_comments(lem, &line);
	if (only_number(line) != 1)
	{
		free(line);
		return (-1);
	}
	(*lem)->ant = create_ant_node(0);
	if (((*lem)->ant->ants = ft_atoi(line)) <= 0)
		print_error(lem, 1);
	free(line);
	create_ant_list((*lem)->ant);
	return (1);
}

void		create_ant_list(t_ant *ant)
{
	t_ant	*tmp;
	int		num;

	num = 1;
	while (num <= ant->ants)
	{
		tmp = create_ant_node(num);
		add_ant_node(ant, tmp);
		num++;
	}
}

t_ant		*create_ant_node(int n)
{
	t_ant	*node;

	node = (t_ant*)malloc(sizeof(t_ant));
	node->moves = 0;
	node->ants = 0;
	node->number = n;
	node->next = NULL;
	node->route = NULL;
	return (node);
}

void		add_ant_node(t_ant *ant, t_ant *temp)
{
	t_ant	*tmp;

	tmp = ant;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = temp;
}

void		init_lemin(t_lem **lem)
{
	*lem = (t_lem*)malloc(sizeof(t_lem));
	(*lem)->data = ft_strnew(0);
	(*lem)->ant = NULL;
	(*lem)->adj = NULL;
	(*lem)->ant = 0;
	(*lem)->gra = NULL;
	(*lem)->que = NULL;
	(*lem)->room = NULL;
	(*lem)->route = NULL;
}
