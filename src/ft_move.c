/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skgatle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 05:24:16 by skgatle           #+#    #+#             */
/*   Updated: 2017/12/08 05:24:24 by skgatle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void		del_last_item(t_backpack *backpack)
{
	t_backpack	*tmp;

	tmp = backpack;
	while (tmp->next && tmp->next->next)
		tmp = tmp->next;
	if (tmp->next)
	{
		free(tmp->next);
		tmp->next = NULL;
	}
}

static int		is_in_backpack(char *id, t_backpack *backpack)
{
	t_backpack	*tmp;

	tmp = backpack;
	while (tmp)
	{
		if (ft_strcmp(tmp->id, id) == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static void		add_room_to_backpack(t_room *room, t_backpack **backpack)
{
	t_backpack	*tmp;

	tmp = *backpack;
	if (!tmp)
	{
		(*backpack) = (t_backpack *)malloc(sizeof(t_backpack));
		(*backpack)->next = NULL;
		(*backpack)->id = room->id;
		if (room->is_start || room->is_end)
		{
			(*backpack)->st_end = 1;
		}
		else
			(*backpack)->st_end = 0;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = (t_backpack *)malloc(sizeof(t_backpack));
		tmp->next->next = NULL;
		tmp->next->id = room->id;
		if (room->is_start || room->is_end)
			tmp->next->st_end = 1;
		else
			tmp->next->st_end = 0;
	}
}

static t_backpack	*copy_backpack(t_backpack *backpack)
{
	t_backpack	*copy_bp;
	t_backpack	*start;
	t_backpack	*tmp;

	if (backpack)
	{
		tmp = backpack;
		copy_bp = (t_backpack *)malloc(sizeof(t_backpack));
		copy_bp->id = tmp->id;
		copy_bp->st_end = tmp->st_end;
		start = copy_bp;
		while (tmp->next)
		{
			copy_bp->next = (t_backpack *)malloc(sizeof(t_backpack));
			copy_bp->next->id = tmp->next->id;
			copy_bp->next->st_end = tmp->next->st_end;
			copy_bp->next->next = NULL;
			tmp = tmp->next;
			copy_bp = copy_bp->next;
		}
		return (start);
	}
	return (NULL);
}

static void		leave_backpack(t_room *room, t_backpack *backpack)
{
	t_backpack	*copy_bp;

	copy_bp = copy_backpack(backpack);
	room->backpack = copy_bp;
}

static void	print_bp(t_backpack *backpack)
{
	t_backpack *tmp;

	tmp = backpack;
	while (tmp)
	{
		ft_putstr(tmp->id);
		ft_putstr(", ");
		tmp = tmp->next;
	}
	ft_putstr("\n ");
}

static void	room_is_end(t_room *room, t_backpack *backpack)
{
	t_routes	*tmp;

	print_bp(backpack);
	ft_putstr("\n");
	tmp = room->routes;
	if (room->routes == NULL)
	{
		room->routes = (t_routes *)malloc(sizeof(t_routes));
		room->routes->route = copy_backpack(backpack);
		room->routes->next = NULL;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = (t_routes *)malloc(sizeof(t_routes));
		tmp->next->route = copy_backpack(backpack);
		tmp->next->next = NULL;
	}
}

void		ft_move_lem(t_room *room, t_backpack *backpack)
{
	leave_backpack(room, backpack);
	add_room_to_backpack(room, &backpack);
	if (room->is_end)
	{
		room_is_end(room, backpack);
		return ;
	}
	else
	{
		room->connect = room->start_connections;
		while (room->connect)
		{
			if ((!(is_in_backpack(room->connect->room->id, backpack))))
			{
				ft_move_lem(room->connect->room, backpack);
				del_last_item(backpack);
			}
			room->connect = room->connect->next;
		}
	}
}
