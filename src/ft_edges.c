/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_edges.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skgatle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 08:26:11 by skgatle           #+#    #+#             */
/*   Updated: 2017/12/13 08:26:14 by skgatle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static t_connect	*new_edge(t_room *new_room)
{
	t_connect	*new_edge;

	new_edge = (t_connect *)malloc(sizeof(t_connect));
	new_edge->next = NULL;
	new_edge->room = new_room;
	return (new_edge);
}

void	ft_add_connections_end(t_connect **start, t_room *new_room)
{
	t_connect	*tmp;

	if (*start == NULL || (*start)->room == NULL)
		*start = new_edge(new_room);
	else
	{
		tmp = *start;
		while (tmp->next)
		{
			if (ft_strcmp(tmp->room->id, new_room->id) == 0)
				return ;
			tmp = tmp->next;
		}
		if (ft_strcmp(tmp->room->id, new_room->id) == 0)
			return ;
		tmp->next = new_edge(new_room);
	}
}
