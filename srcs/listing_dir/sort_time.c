/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zadrien <zadrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 21:02:02 by zadrien           #+#    #+#             */
/*   Updated: 2017/11/04 17:22:08 by zadrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		put_front(t_ls **lst, t_ls *n, t_ls *beg, t_ls *pre)
{
	if (pre != NULL)
		pre->next = n;
	n->next = *lst;
	*lst = n;
	if (pre != NULL)
		*lst = beg;
}

static void		ascii(t_ls **lst, t_ls *n, t_ls *beg, t_ls *pre)
{
	while (*lst && (*lst)->buf.st_mtime >= n->buf.st_mtime
	&& (*lst)->buf.st_mtimespec.tv_nsec == n->buf.st_mtimespec.tv_nsec
	&& ft_strcmp((*lst)->name, n->name) < 0)
	{
		pre = *lst;
		*lst = (*lst)->next;
	}
	if (*lst == NULL)
	{
		pre->next = n;
		n->next = *lst;
		*lst = beg;
	}
	else if (ft_strcmp((*lst)->name, n->name) > 0
		|| (*lst)->buf.st_mtime < n->buf.st_mtime
		|| (*lst)->buf.st_mtimespec.tv_nsec < n->buf.st_mtimespec.tv_nsec)
		put_front(lst, n, beg, pre);
	else
	{
		n->next = (*lst)->next;
		(*lst)->next = n;
		*lst = beg;
	}
}

static void		put_nsec(t_ls **lst, t_ls *n, t_ls *beg, t_ls *pre)
{
	while (*lst && (*lst)->buf.st_mtime == n->buf.st_mtime
		&& (*lst)->buf.st_mtimespec.tv_nsec > n->buf.st_mtimespec.tv_nsec)
	{
		pre = *lst;
		*lst = (*lst)->next;
	}
	if (*lst == NULL)
		ft_addhead(lst, n);
	else if ((*lst)->buf.st_mtime < n->buf.st_mtime
		|| (*lst)->buf.st_mtimespec.tv_nsec < n->buf.st_mtimespec.tv_nsec)
		put_front(lst, n, beg, pre);
	else
		ascii(lst, n, beg, pre);
}

void			ft_addbetween(t_ls **lst, t_ls *n, t_ls *beg, t_ls *pre)
{
	pre->next = n;
	n->next = *lst;
	*lst = beg;
}

void			ft_putsec(t_ls **lst, t_ls *n)
{
	t_ls		*beg;
	t_ls		*pre;

	beg = *lst;
	pre = NULL;
	if (*lst == NULL)
		ft_addhead(lst, n);
	else
	{
		while (*lst && (*lst)->buf.st_mtime > n->buf.st_mtime)
		{
			pre = *lst;
			*lst = (*lst)->next;
		}
		if (*lst == NULL)
			ft_addbetween(lst, n, beg, pre);
		else if ((*lst)->buf.st_mtime < n->buf.st_mtime)
			put_front(lst, n, beg, pre);
		else
			put_nsec(lst, n, beg, pre);
	}
}
