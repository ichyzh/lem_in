/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_one_route.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichyzh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 16:30:38 by ichyzh            #+#    #+#             */
/*   Updated: 2018/08/08 16:30:40 by ichyzh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

int			find_one_route(t_route **route)
{
	t_route	*tmp;

	tmp = *route;
	while (tmp)
	{
		if (tmp->count == 1)
			return (1);
		tmp = tmp->next_route;
	}
	return (0);
}

void		place_one_route(t_route **head, t_ant **ant)
{
	t_ant	*tmp;
	t_route	*route;

	route = *head;
	(*ant)->moves = 1;
	tmp = (*ant)->next;
	while (route)
	{
		if (route->count == 1)
			break ;
		route = route->next_route;
	}
	while (tmp)
	{
		tmp->route = route;
		tmp = tmp->next;
	}
}

int			node_root(t_que *prev, t_adjlist *node, t_que *que)
{
	t_que	*q;
	t_que	*t;

	q = que;
	while (q)
	{
		if (ft_strequ(q->name, prev->name))
		{
			t = q;
			while (t->prev)
			{
				if (ft_strequ(t->name, node->name))
					return (1);
				t = t->prev;
			}
		}
		q = q->next;
	}
	return (0);
}

int			same_root(t_que *prev, t_adjlist *node, t_que *que)
{
	t_que	*tmp;
	t_que	*t;
	t_que	*q;

	tmp = que;
	while (tmp)
	{
		if (ft_strequ(tmp->name, node->name))
		{
			t = tmp;
			while (t->prev)
			{
				q = prev;
				while (q)
				{
					if (ft_strequ(t->name, q->name))
						return (1);
					q = q->prev;
				}
				t = t->prev;
			}
		}
		tmp = tmp->next;
	}
	return (0);
}

t_que		*ret_prev_node(int pos, t_que *route, t_que *prev)
{
	t_que	*tmp;

	if (prev)
	{
		tmp = route;
		while (tmp)
		{
			if (tmp->pos == pos)
			{
				if (tmp->prev && ft_strequ(tmp->prev->name, prev->name))
					return (tmp);
			}
			tmp = tmp->next;
		}
	}
	tmp = route;
	while (tmp)
	{
		if (tmp->pos == pos)
			return (tmp);
		tmp = tmp->next;
	}
	return (tmp);
}
