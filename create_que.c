/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_que.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichyzh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 16:29:38 by ichyzh            #+#    #+#             */
/*   Updated: 2018/08/08 16:29:40 by ichyzh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void		add_in_queue(t_que *cur, t_que **q, t_que *prev)
{
	t_que	*node;
	t_que	*tmp;

	tmp = *q;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->next && tmp->next->s_e == 2)
			break ;
	}
	if (tmp->next && tmp->next->s_e == 2)
	{
		node = tmp->next;
		tmp->next = cur;
		tmp->next->next = node;
	}
	else
		tmp->next = cur;
	if (cur->s_e != 1)
		tmp->next->prev = prev;
}

t_que		*create_que(t_room *room, int p, int s)
{
	t_que	*node;
	t_room	*tmp;

	tmp = room;
	while (tmp)
	{
		if (tmp->pos == s)
			break ;
		else
			tmp = tmp->next;
	}
	if (!tmp)
		exit(-1);
	node = create_q_node(tmp->name, p, s);
	return (node);
}

t_que		*create_q_node(char *str, int p, int s)
{
	t_que	*node;

	node = (t_que*)malloc(sizeof(t_que));
	node->name = ft_strdup(str);
	node->pos = s;
	node->s_e = p;
	node->vis = 0;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

int			check_prev(t_que *prev, t_adjlist *node, t_que *que)
{
	t_que	*tmp;

	tmp = prev;
	while (tmp)
	{
		if (ft_strequ(tmp->name, node->name))
			return (1);
		tmp = tmp->prev;
	}
	if ((node_root(prev, node, que) == 1) || (same_root(prev, node, que) == 1))
		return (1);
	return (0);
}

int			check_root(t_que *q)
{
	t_que	*tmp;

	tmp = q;
	while (tmp->prev)
	{
		if (tmp->vis == 1)
			return (0);
		tmp = tmp->prev;
	}
	return (1);
}
