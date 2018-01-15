/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skgatle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 07:12:29 by skgatle           #+#    #+#             */
/*   Updated: 2017/12/13 07:15:57 by skgatle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static t_room	*populate_room(char **line, int num_of_ants)
{
	char	**info;
	t_room	*room;
	int		s_or_e;

	s_or_e = 0;
	while ((*line)[0] == '#' && (*line)[1] != '#')
	{
		free(*line);
		get_next_line(0, line);
	}
	if (ft_strstr(*line, "##"))
	{
		if (!ft_strcmp(*line, "##start"))
			s_or_e = 1;
		else if (!ft_strcmp(*line, "##end"))
			s_or_e = 2;
		free(*line);
		get_next_line(0, line);
	}
	if (check_char(line, ' ') == 2)
	{
		info = ft_strsplit(*line, ' ');
		if (check_num(info[1]) && check_num(info[2]))
		{
			room = new_room(info, s_or_e, num_of_ants);
			return (room);
		}
	}
	return (NULL);
}

t_room			*ft_process_file(void)
{
	t_room	*room;
	t_room	*start;
	char	*line;
	int		num_of_ants;
	int		ret;

	num_of_ants = 0;
	start = NULL;
	while (get_next_line(0, &line) > 0 && !ft_strchr(line, '-'))
	{
		if (!ft_strchr(line, ' ') && !num_of_ants && check_num(line))
			num_of_ants = ft_atoi(line);
		else if ((room = populate_room(&line, num_of_ants)))
			ft_add_to_room_end(&start, room);
		else
			return (start);
		free(line);
	}
	ret = ft_connect_edges(&start, &line);
	free(line);
	while (ret && get_next_line(0, &line) > 0 && ft_strcmp(line, "") != 0)
	{
		ret = ft_connect_edges(&start, &line);
		free(line);
	}
	return (start);
}
