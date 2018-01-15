/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_connections.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skgatle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 05:23:37 by skgatle           #+#    #+#             */
/*   Updated: 2017/12/08 05:25:20 by skgatle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static char	**retrieve_edges(char	**line)
{
	char	**room_info;

	room_info = NULL;
	if ((*line)[0] == '#' && (*line)[1] != '#')
	{
		free(*line);
		if (get_next_line(0, line) < 1 && (!find_char(line, '-')))
			return (NULL);
	}
	room_info = ft_strsplit(*line, '-');
	if (array2d_len(room_info) != 2 || ft_strcmp(*room_info, *(room_info + 1)) == 0)
	{
		while (*room_info != '\0')
			free(*room_info++);
		room_info = NULL;
	}
	return (room_info);
}

int		ft_connect_edges(t_room **room, char **line)
{
	char	**connections;
	t_room	*tmp;
	t_room	*tmp2;

	tmp = *room;
	tmp2 = *room;
	if ((connections = retrieve_edges(line)))
	{
		while (ft_strcmp(*connections, tmp->id) != 0)
		{
			if((tmp = tmp->next) == NULL)
				return (0);
		}
		while (ft_strcmp(*(connections + 1), tmp2->id) != 0)
		{
			if((tmp2 = tmp2->next) == NULL)
				return (0);
		}
		ft_add_connections_end(&tmp->connect, tmp2);
		ft_add_connections_end(&tmp2->connect, tmp);
		return (1);
	}
	return (0);
}
