/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skgatle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 14:42:31 by skgatle           #+#    #+#             */
/*   Updated: 2017/07/30 16:16:18 by skgatle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *nw_lnk;

	while (lst)
	{
		nw_lnk = f(lst);
		nw_lnk->next = ft_lstmap(lst->next, f);
		return (nw_lnk);
	}
	return (NULL);
}
