/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skgatle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 09:09:46 by skgatle           #+#    #+#             */
/*   Updated: 2017/12/13 09:09:50 by skgatle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static int		process_map(t_room *room)
{
	t_connect	*edge;

	ft_putstr("\n-> Room name: ");
	ft_putstr(room->id);
	ft_putstr("\t-> startFlag = ");
	ft_putstr(ft_itoa(room->is_start));
	ft_putstr("\t-> endFlag = ");
	ft_putstr(ft_itoa(room->is_end));
	edge = room->connect;
	ft_putstr("\n");
	ft_putstr("\t-> Edges: ");
	while (edge)
	{
		ft_putstr(edge->room->id);
		if (edge->next)
			ft_putstr(", ");
		edge = edge->next;
	}
	ft_putstr("\n");
	return (1);
}

void	display_map(t_room **room)
{
	t_room		*tmp;

	tmp = *room;
	while (tmp)
	{
		process_map(tmp);
		tmp = tmp->next;
	}
	process_routes_needed(room);
	start_connections(room);
	init_routes(room);
}
