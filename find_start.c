/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichyzh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 16:28:38 by ichyzh            #+#    #+#             */
/*   Updated: 2018/08/08 16:28:40 by ichyzh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

int			only_number(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (-1);
	if (ft_isdigit(str[i]))
	{
		while (ft_isdigit(str[i]) && str[i])
			i++;
	}
	if (str[i] == '\0')
		return (1);
	return (-1);
}

int			corect_room(t_room *room)
{
	t_room	*tmp;
	int		count;
	int		i;

	i = 0;
	count = 0;
	tmp = room;
	while (tmp)
	{
		if (tmp->s_e == 1)
			count++;
		if (tmp->s_e == 2)
			i++;
		tmp = tmp->next;
	}
	if (count != 1 || i != 1)
		return (0);
	return (1);
}

int			ft_listlen(t_room **room)
{
	int		i;
	t_room	*tmp;

	i = 0;
	tmp = *room;
	while (tmp)
	{
		tmp->pos = i;
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int			check_pos_node(t_room **room, char *str)
{
	t_room	*tmp;

	tmp = *room;
	while (tmp)
	{
		if (ft_strequ(tmp->name, str))
			return (tmp->pos);
		else
			tmp = tmp->next;
	}
	return (-1);
}

int			find_start(t_room *room)
{
	t_room	*tmp;

	tmp = room;
	while (tmp)
	{
		if (tmp->s_e == 1)
			return (tmp->pos);
		else
			tmp = tmp->next;
	}
	return (-1);
}
