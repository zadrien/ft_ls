/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zadrien <zadrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:13:37 by zadrien           #+#    #+#             */
/*   Updated: 2017/11/04 17:20:09 by zadrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_addhead(t_ls **lst, t_ls *new)
{
	if (*lst != NULL && new != NULL)
	{
		new->next = *lst;
		*lst = new;
	}
	else
		*lst = new;
}

int		ft_addnode(t_ls **lst, t_ls *node)
{
	t_ls	*tmp;

	tmp = *lst;
	if (*lst != NULL && node != NULL)
	{
		node->next = tmp->next;
		tmp->next = node;
		return (1);
	}
	return (0);
}

void	ft_asciisort(t_ls **lst, t_ls *new, int flags)
{
	if ((flags & LOW_R_FLAG))
		ft_lstrevcmp(lst, new);
	else
		ft_lstcmp(lst, new);
}

void	ft_lstrevcmp(t_ls **lst, t_ls *new)
{
	t_ls *tmp;

	tmp = *lst;
	if ((*lst) == NULL)
		(*lst) = new;
	else if (ft_strcmp(new->name, (*lst)->name) > 0)
		ft_addhead(lst, new);
	else
	{
		while (tmp->next != NULL)
		{
			if (ft_strcmp(new->name, tmp->next->name) > 0
					&& ft_addnode(&tmp, new) == 1)
				return ;
			tmp = tmp->next;
		}
		tmp->next = new;
	}
}

void	ft_lstcmp(t_ls **lst, t_ls *new)
{
	t_ls *tmp;

	tmp = *lst;
	if ((*lst) == NULL)
		(*lst) = new;
	else if (ft_strcmp(new->name, (*lst)->name) < 0)
		ft_addhead(lst, new);
	else
	{
		while (tmp->next != NULL)
		{
			if (ft_strcmp(new->name, tmp->next->name) < 0
					&& ft_addnode(&tmp, new) == 1)
				return ;
			tmp = tmp->next;
		}
		tmp->next = new;
	}
}
