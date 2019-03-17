/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_route.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichyzh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 16:29:55 by ichyzh            #+#    #+#             */
/*   Updated: 2018/08/08 16:29:57 by ichyzh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

int			check_same_in_r(char *str, t_route *route)
{
	t_route *tmp;

	tmp = route;
	while (tmp)
	{
		if (ft_strequ(tmp->name, str))
			return (1);
		tmp = tmp->next;
	}
	if (route->next_route)
		check_same_in_r(str, route->next_route);
	return (0);
}

void		create_route(t_que **que, t_route **route)
{
	t_que	*tmp;
	t_route	*tempo;
	int		i;

	i = 0;
	tmp = *que;
	tempo = *route;
	if (tempo != NULL)
	{
		while (tempo->next_route)
			tempo = tempo->next_route;
		while (tmp)
		{
			tempo->next_route = add_to_route(&tempo->next_route, tmp, i);
			i++;
			tmp = tmp->prev;
		}
	}
	while (tmp)
	{
		*route = add_to_route(route, tmp, i);
		i++;
		tmp = tmp->prev;
	}
}

t_route		*add_to_route(t_route **route, t_que *tmp, int i)
{
	t_route	*node;

	node = create_r_node(tmp->name, i, tmp->s_e);
	if (*route == NULL)
	{
		return (node);
	}
	node->next = *route;
	return (node);
}

t_route		*create_r_node(char *str, int i, int s_e)
{
	t_route	*nod;

	nod = (t_route*)malloc(sizeof(t_route));
	nod->ants = 0;
	nod->vis = 0;
	nod->name = ft_strdup(str);
	nod->count = i;
	nod->s_e = s_e;
	nod->next = NULL;
	nod->next_route = NULL;
	return (nod);
}

int			is_start_end(t_room *room, int pos)
{
	t_room	*tmp;

	tmp = room;
	while (tmp)
	{
		if (tmp->pos == pos)
			return (tmp->s_e);
		tmp = tmp->next;
	}
	return (-1);
}
