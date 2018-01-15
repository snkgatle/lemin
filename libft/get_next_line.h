/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skgatle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 20:41:46 by skgatle           #+#    #+#             */
/*   Updated: 2017/07/17 16:11:19 by skgatle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GET_NEXT_LINE_H
# define _GET_NEXT_LINE_H

# define BUFF_SIZE 999

# include <fcntl.h>
# include <string.h>
# include "libft.h"

int							get_next_line(int const fd, char **line);
typedef struct				s_line_info
{
	int						fd;
	char					*content_tmp;
	struct s_line_info		*next;
}							t_line_info;

#endif
