/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_no_conflicts.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skgatle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 05:25:54 by skgatle           #+#    #+#             */
/*   Updated: 2017/12/08 05:26:06 by skgatle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static t_backpack	*conflict_route(t_backpack *r1, t_backpack *r2)
{
	t_backpack	*start_old;
	t_backpack	*start_new;
	t_backpack	*route_new;
	t_backpack	*route_old;

	route_old = r1;
	route_new = r2;
	start_new = route_new;
	start_old = route_old;
	while(route_old)
	{
		while (route_new)
		{
			if (!route_new->st_end && !route_old->st_end &&
				ft_strcmp(route_new->id, route_old->id) == 0)
				return (start_old);
			route_new = route_new->next;
		}
		route_new = start_new;
		route_old = route_old->next;
	}
	return (NULL);
}

static t_routes	*lst_cpy(t_routes **to_copy)
{
	t_routes	*copy;
	t_routes	*copy_start;
	t_routes	*tmp;

	tmp = *to_copy;
	copy = (t_routes *)malloc(sizeof(t_routes));
	copy->route = tmp->route;
	copy->compatable = NULL;
	copy->next = NULL;
	copy->checking = NULL;
	copy_start = copy;
	while (tmp->next)
	{
		copy->next = (t_routes *)malloc(sizeof(t_routes));
		copy->next->route = tmp->next->route;
		copy->next->compatable = NULL;
		copy->next->next = NULL;
		copy->next->checking = NULL;
		tmp = tmp->next;
		copy = copy->next;
	}
	return (copy_start);
}

static void		add_to_route(t_routes **lst, t_routes *new)
{
	t_routes	*tmp;

	tmp = *lst;
	if (*lst)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = (t_routes *)malloc(sizeof(t_routes));
		tmp->next->next = NULL;
		tmp->next->checking = new->checking;
		tmp->next->compatable = new->compatable;
		tmp->next->route = new->route;
	}
	else
	{
		*lst = (t_routes *)malloc(sizeof(t_routes));
		(*lst)->next = NULL;
		(*lst)->checking = new->checking;
		(*lst)->compatable = NULL;
		(*lst)->route = new->route;
	}
}

static t_routes		*conflict(t_routes *check, t_routes **start)
{
	t_routes	*to_check_start;
	t_routes	*to_check;
	t_routes	*tmp;
	t_routes	*copy_check;
	t_routes	*copy_tmp;

	to_check = check->checking;
	to_check_start = to_check;
	tmp = *start;
	while (tmp)
	{
		while (to_check && !conflict_route(to_check->route, tmp->route))
			to_check = to_check->next;
		if (to_check == NULL)
		{
			to_check = to_check_start;
			copy_check = lst_cpy(&to_check);
			copy_tmp = lst_cpy(&tmp);
			add_to_route(&copy_check, tmp);
			copy_tmp->checking = copy_check;
			copy_tmp->compatable = conflict(copy_tmp, start);
			copy_tmp->checking = copy_check;
			add_to_route(&check->compatable, copy_tmp);
		}
		to_check = to_check_start;
		tmp = tmp->next;
	}
	return (check->compatable);
}

void	ft_find_no_conflicts(t_routes **start)
{
	t_routes	*tmp;
	tmp = *start;
	while (tmp)
	{
		tmp->checking = (t_routes *)malloc(sizeof(t_routes));
		tmp->checking->next = NULL;
		tmp->checking->route = tmp->route;
		tmp->checking->compatable = NULL;
		tmp->checking->checking = NULL;
		tmp->compatable = NULL;
		tmp = tmp->next;
	}
	tmp = *start;
	while (tmp)
	{
		conflict(tmp, start);
		tmp = tmp->next;
	}
}
