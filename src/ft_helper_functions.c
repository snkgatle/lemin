/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skgatle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 08:58:52 by skgatle           #+#    #+#             */
/*   Updated: 2017/12/12 08:58:55 by skgatle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int         check_char(char **line, char c)
{
    char	*p_line;
    int		cnt;

    cnt = 0;
    p_line = *line;
    if (*p_line == '#')
        return (0);
    while (*p_line)
        if (*p_line++ == c)
            cnt++;
    return (cnt);
}

int         check_num(char *str)
{
    while (*str)
    {
        if (!(*str <= '9' && *str >= '0'))
            return (0);
        str = str + 1;
    }
    return (1);
}

int			find_char(char **line, char c)
{
	if (**line == '#')
		return (0);
	return (!ft_strchr(*line, c)? 0 : 1);
}

int			array2d_len(char **arr)
{
	int		len;
	len = 0;
	while (arr[len] != '\0')
		len++;
	return(len);
}
