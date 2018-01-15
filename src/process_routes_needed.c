/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_routes_needed.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skgatle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 05:28:24 by skgatle           #+#    #+#             */
/*   Updated: 2017/12/08 05:28:29 by skgatle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

t_room			*return_end(t_room **room)
{
	t_room	*p_room;

	p_room = *room;
	while (p_room)
	{
		if (p_room->is_end)
			return (p_room);
		p_room = p_room->next;
	}
	return (NULL);
}

t_room			*return_start(t_room **room)
{
	t_room	*p_room;

	p_room = *room;
	while (p_room)
	{
		if (p_room->is_start)
			return (p_room);
		p_room = p_room->next;
	}
	return (NULL);
}

static int	link_list_len(t_connect *edges)
{
	int		cnt;

	cnt = 0;
	while (edges)
	{
		edges = edges->next;
		cnt++;
	}
	return (cnt);
}

void	process_routes_needed(t_room **room) {
	t_room *start;
	t_room *end;
	int start_num;
	int end_num;

	if ((start = return_start(room))) {
		if ((end = return_end(room))) {
			start_num = link_list_len(start->connect);
			end_num = link_list_len(end->connect);
			if (start_num > end_num)
				end->routes_needed = start_num;
			else
				end->routes_needed = end_num;
			return;
		}
	}
	ft_error_handler(2, 'e');
}
