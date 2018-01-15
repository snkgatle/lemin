/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skgatle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 05:22:27 by skgatle           #+#    #+#             */
/*   Updated: 2017/12/08 05:22:51 by skgatle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static void draw_from_start(t_room **start)
{
	t_room		*room;
	t_backpack	*backpack;

	backpack = NULL;
	room = *start;
	ft_move_lem(room, backpack);
}

void	init_routes(t_room **room)
{
	t_room	*start;

	if ((start = return_start(room)))
		draw_from_start(&start);
	else
		ft_error_handler(2, 'e');
}
