/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichyzh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 16:29:09 by ichyzh            #+#    #+#             */
/*   Updated: 2018/08/08 16:29:10 by ichyzh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void		check_path(t_lem **lem)
{
	int		s;
	int		curr;
	int		p;
	t_que	*temp;

	s = find_start((*lem)->room);
	p = is_start_end((*lem)->room, s);
	(*lem)->que = create_que((*lem)->room, p, s);
	temp = (*lem)->que;
	while (temp)
	{
		if (temp->s_e == 2)
		{
			temp = temp->next;
			continue ;
		}
		curr = check_pos_node(&(*lem)->room, temp->name);
		create_path(lem, &temp, curr, p);
		temp = temp->next;
	}
	if ((*lem)->route == NULL)
		print_error(lem, 3);
}

void		create_path(t_lem **lem, t_que **temp, int curr, int p)
{
	t_adjlist	*tmp;
	t_que		*prev;
	t_que		*curent;

	tmp = (*lem)->gra->node[curr];
	prev = ret_prev_node(curr, (*lem)->que, (*temp)->prev);
	while (tmp)
	{
		p = is_start_end((*lem)->room, tmp->pos);
		if (find_same((*lem)->que, tmp, prev))
		{
			curent = create_q_node(tmp->name, p, tmp->pos);
			add_in_queue(curent, temp, prev);
		}
		if (curent && curent->s_e == 2 && check_root(curent))
		{
			create_route(&curent, &(*lem)->route);
			dequeue(&(*lem)->que, (*lem)->route);
			curent = NULL;
		}
		tmp = tmp->next;
	}
}

void		ft_lst_push_back(t_room **begin_list, t_room *temp)
{
	t_room *tmp;

	if (*begin_list == NULL)
	{
		*begin_list = temp;
		return ;
	}
	tmp = *begin_list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = temp;
}

int			val_link(char *str, t_room **room)
{
	t_room	*tmp;

	tmp = *room;
	while (tmp)
	{
		if (ft_strequ(tmp->name, str))
			return (1);
		else
			tmp = tmp->next;
	}
	return (-1);
}

int			find_same(t_que *que, t_adjlist *node, t_que *prev)
{
	t_que	*tmp;

	tmp = que;
	if (check_prev(prev, node, que))
		return (0);
	while (tmp)
	{
		if (ft_strequ(tmp->name, node->name))
		{
			if (tmp->s_e == 2)
				return (1);
			if (tmp->prev && tmp->prev->name != prev->name)
			{
				tmp = tmp->next;
				continue ;
			}
			else
				return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}
