/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_room.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skgatle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 09:51:10 by skgatle           #+#    #+#             */
/*   Updated: 2017/12/12 09:51:12 by skgatle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	ft_add_to_room_end(t_room **start, t_room *new_node)
{
	t_room *tmp;

	if (*start == NULL)
		*start = new_node;
	else
	{
		tmp = *start;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_node;
		new_node->next = NULL;
	}
}

t_room				*new_room(char **input, int start_end, int num_of_ants)
{
	t_room	*room;

	room = (t_room *)malloc(sizeof(t_room));
	room->id = input[0];
	room->posx = input[1];
	room->posy = input[2];
	room->next = NULL;
	room->is_start = 0;
	room->is_end = 0;
	room->num_of_ants = 0;
	room->connect = NULL;
	room->backpack = NULL;
	room->routes = NULL;
	if (start_end == 1 && (room->is_start = 1))
		room->num_of_ants = num_of_ants;
	else if (start_end == 2)
		room->is_end = 1;
	return (room);
}

void				start_connections(t_room **room)
{
	t_room	*tmp;

	tmp = *room;
	while (tmp)
	{
		tmp->start_connections = tmp->connect;
		tmp = tmp->next;
	}
}
