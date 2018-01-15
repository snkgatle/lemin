/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skgatle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 05:22:01 by skgatle           #+#    #+#             */
/*   Updated: 2017/12/08 05:22:12 by skgatle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		main()
{
	t_room		*room;
	t_room		*end;
	t_best		*best;

	room = ft_process_file();
	display_map(&room);
	end = return_end(&room);
	ft_find_no_conflicts(&end->routes);
	best = ft_find_best(&end->routes);
	ft_putstr("Routes on Map = ");
	ft_putendl(ft_itoa(best->num_routes));
	ft_putstr("Length of route = ");
	ft_putendl(ft_itoa(best->len_tot));
	ft_putstr("\n");
	ft_simulate(&room, best);
	return (1);
}
