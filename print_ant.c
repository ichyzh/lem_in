/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ant.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichyzh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 16:30:13 by ichyzh            #+#    #+#             */
/*   Updated: 2018/08/08 16:30:15 by ichyzh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void		print_ant(t_ant *temp)
{
	write(1, "L", 1);
	ft_putnbr(temp->number);
	write(1, "-", 1);
	ft_putstr(temp->route->next->name);
}

void		move_ant(t_ant **ant, t_ant *temp)
{
	while ((*ant)->moves--)
	{
		temp = (*ant)->next;
		while (temp)
		{
			temp->route->vis = 0;
			if ((temp->route->next != NULL && temp->route->next->vis != 0
				&& temp->route->next->s_e != 2) || temp->ants == -1)
			{
				temp = temp->next;
				continue ;
			}
			if (temp->route->next != NULL && temp->route->next->s_e == 2)
				temp->ants = -1;
			print_ant(temp);
			if (temp->route->next->s_e != 2)
				temp->route->next->vis = temp->number;
			if (temp->next && temp->next->route->next->vis == 0)
				write(1, " ", 1);
			temp->route = temp->route->next;
			temp = temp->next;
		}
		write(1, "\n", 1);
	}
}

void		add_route_to_ant(t_route **h, t_route *r, t_ant **ant, int ants)
{
	t_route	*tmp;
	t_ant	*tempant;

	(*ant)->moves = (*h)->ants + (*h)->count - 1;
	if (find_one_route(h) == 1)
	{
		place_one_route(h, ant);
		return ;
	}
	tmp = *h;
	if (r)
		tmp = r;
	tempant = (*ant)->next;
	if (ants > 0)
	{
		tempant->route = tmp;
		tmp->ants--;
		ants--;
		if (tmp->next_route && tmp->next_route->ants > 0)
			add_route_to_ant(h, tmp->next_route, &tempant, ants);
		else
			add_route_to_ant(h, NULL, &tempant, ants);
	}
}

void		count_ants(int ants, t_route **head, t_route *route)
{
	t_route	*tmp;

	if (route)
		tmp = route;
	else
		tmp = *head;
	if (ants > 0)
	{
		if (tmp->next_route && (tmp->count + tmp->ants >=
			tmp->next_route->count + tmp->next_route->ants))
		{
			tmp->ants++;
			ants--;
			count_ants(ants, head, tmp->next_route);
		}
		else
		{
			tmp->ants++;
			ants--;
			count_ants(ants, head, NULL);
		}
	}
}

void		dequeue(t_que **temp, t_route *route)
{
	t_que	*tmp;

	tmp = *temp;
	while (tmp)
	{
		if (tmp->pos == 0)
		{
			tmp = tmp->next;
			continue;
		}
		else if (check_same_in_r(tmp->name, route) && tmp->s_e != 2)
			tmp->vis = 1;
		tmp = tmp->next;
	}
}
