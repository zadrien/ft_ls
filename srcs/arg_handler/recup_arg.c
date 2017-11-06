/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zadrien <zadrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 16:26:12 by zadrien           #+#    #+#             */
/*   Updated: 2017/11/04 15:56:37 by zadrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

int		init_node(t_ls **node, char *str)
{
	if (!((*node) = (t_ls*)malloc(sizeof(t_ls))))
		return (0);
	(*node)->name = ft_strdup(str);
	(*node)->path = NULL;
	(*node)->time = NULL;
	// (*node).buf = NULL;
	(*node)->next = NULL;
	return (1);
}

void	add_first(t_ls **lst, t_ls **prev, t_ls **cur, t_ls **node)
{
	t_ls	*tmp;

	tmp = *node;
	if (*prev)
	{
		(*prev)->next = tmp;
		tmp->next = *cur;
	}
	else
	{
		*lst = tmp;
		tmp->next = *cur;
	}
}

void	complete_lst(t_ls **lst, t_ls **node)
{
	t_ls	*tmp;
	t_ls	*prev;

	prev = NULL;
	if ((tmp = *lst))
	{
		while (tmp)
		{
			if (ft_strcmp(tmp->name, (*node)->name) >= 0)
				return (add_first(lst, &prev, &tmp, node));
			prev = tmp;
			tmp = tmp->next;
		}
		if (!tmp)
			prev->next = *node;
	}
	else
		*lst = *node;
}

t_ls	*opt_l_act(char **av, int flags, t_ls **err, t_ls **dir)
{
	int			i;
	t_ls		*lst;
	t_ls		*tmp;

	i = -1;
	lst = NULL;
	tmp = NULL;
	(void)flags;
	while (av[++i])
		if (init_node(&tmp, av[i]))
		{
			if (!lstat(av[i], &tmp->buf))
			{
				if (S_ISREG(tmp->buf.st_mode) || S_ISLNK(tmp->buf.st_mode))
					complete_lst(&lst, &tmp);
				else if (S_ISDIR(tmp->buf.st_mode))
					complete_lst(dir, &tmp);
			}
			else
				complete_lst(err, &tmp);
		}
	return (lst);
}

t_ls	*no_l_opt(char **av, int flags, t_ls **err, t_ls **dir)
{
	int			i;
	t_ls		*lst;
	t_ls		*tmp;

	i = -1;
	lst = NULL;
	tmp = NULL;
	(void)flags;
	while (av[++i])
		if (init_node(&tmp, av[i]))
		{
			if (!stat(av[i], &tmp->buf))
			{
				if (S_ISREG(tmp->buf.st_mode))
					complete_lst(&lst, &tmp);
				else if (S_ISDIR(tmp->buf.st_mode))
					complete_lst(dir, &tmp);
			}
			else
				complete_lst(err, &tmp);
		}
	return (lst);
}

t_ls	*return_file(char **av, int flags, t_ls **err, t_ls **dir)
{
	if (flags & LOW_L_FLAG)
		return (opt_l_act(av, flags, err, dir));
	else
		return (no_l_opt(av, flags, err, dir));
	return (NULL);
}

// t_list	*return_dir(int ac, char *av, int flags)
