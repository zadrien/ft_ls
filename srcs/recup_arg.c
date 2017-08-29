/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zadrien <zadrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 16:26:12 by zadrien           #+#    #+#             */
/*   Updated: 2017/08/28 17:17:46 by zadrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

int		init_node(t_arg **node, char *str)
{
	if (!((*node) = (t_arg*)malloc(sizeof(t_arg))))
		return (0);
	(*node)->str = ft_strdup(str);
	(*ndoe)->next = NULL;
}

void	complete_lst(t_arg **lst, t_arg **node)
{
	t_arg	*tmp;
	t_arg	*prev;

	prev = NULL;
	if (*lst)
	{
		tmp = *lst;
		while (tmp)
		{
			if (ft_strcmp(tmp->arg, (*node)->arg) < 0)
				add_first(*prev, )
		}
	}
	else
		*lst = *node;
}

t_arg	*return_file(char **av, int flags, t_arg **err)
{
	int		i;
	t_arg	*lst;
	t_arg	*tmp;
	struct stat buf;

	i = -1;
	lst = NULL;
	tmp = NULL;
	while (av[++i])
	{
		if (((flags & LOW_L_FLAG))
		{
			if (lstat(av[i], &buf))
			{
				if (S_ISREG(buf.st_mode) || S_ISLNK(buf.st_mode))
					if (init_node(&tmp, av[i]))
					{
						complete_lst(&lst, &tmp);
						ft_bzero(av[i], ft_strlen(av[i]));
					}
			}
			else
				complete_lst(err, &tmp);
		}
		else if (!(flags & LOW_L_FLAG))
		{
			if (stat(av[i], &buf))
			{
				if (S_ISREG(buf.st_mode))
					if (init_node(&tmp, av[i]))
					{
						complete_lst(&lst, &tmp);
						ft_bzero(av[i], ft_strlen(av[i]));
					}
			}
			else
				complete_lst(err, &tmp);
		}
	}
}

t_list	*return_dir(int ac, char *av, int flags)
