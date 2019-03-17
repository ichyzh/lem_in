/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_link.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichyzh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 16:28:51 by ichyzh            #+#    #+#             */
/*   Updated: 2018/08/08 16:28:52 by ichyzh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void		check_link(char **str, t_lem **lem)
{
	while (ft_strchr(*str, '-'))
	{
		if (add_link(str, lem) == 1)
		{
			ft_strdel(str);
			get_next_line(0, str);
			if (*str)
				save_data(lem, *str);
		}
		else
		{
			ft_strdel(str);
			break ;
		}
	}
	if (*str && *str[0] == '#')
	{
		ft_strdel(str);
		get_next_line(0, str);
		if (*str)
			save_data(lem, *str);
		check_link(str, lem);
	}
}

int			add_link(char **str, t_lem **lem)
{
	char	**s;
	int		i;

	i = 0;
	while (*str[0] == '#')
	{
		ft_strdel(str);
		get_next_line(0, str);
		if (*str)
			save_data(lem, *str);
	}
	s = ft_strsplit(*str, '-');
	while (s[i])
		i++;
	if ((val_link(s[0], &(*lem)->room) == 1) &&
		(val_link(s[1], &(*lem)->room) == 1) && i == 2)
	{
		add_edge((*lem)->gra, s[0], s[1], &(*lem)->room);
		ft_strdel(str);
		ft_clear_arr(s);
		return (1);
	}
	ft_clear_arr(s);
	return (0);
}

t_graph		*create_graph(int len)
{
	t_graph	*graph;
	int		i;

	i = 0;
	graph = (t_graph*)malloc(sizeof(graph));
	graph->node = (t_adjlist**)malloc(sizeof(t_adjlist*) * len);
	while (i < len)
	{
		graph->node[i] = NULL;
		i++;
	}
	return (graph);
}

t_adjlist	*create_node(char *name, int pos)
{
	t_adjlist *node;

	node = (t_adjlist*)malloc(sizeof(t_adjlist));
	node->name = ft_strdup(name);
	node->pos = pos;
	node->next = NULL;
	return (node);
}

void		add_edge(t_graph *graph, char *v1, char *v2, t_room **room)
{
	int			src;
	int			dst;
	t_adjlist	*node;
	t_adjlist	*tmp;

	src = check_pos_node(room, v1);
	dst = check_pos_node(room, v2);
	tmp = graph->node[src];
	while (tmp)
	{
		if (ft_strequ(tmp->name, v2))
			return ;
		tmp = tmp->next;
	}
	node = create_node(v2, dst);
	node->next = graph->node[src];
	graph->node[src] = node;
	node = create_node(v1, src);
	node->next = graph->node[dst];
	graph->node[dst] = node;
}
