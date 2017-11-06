/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zadrien <zadrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 18:24:21 by zadrien           #+#    #+#             */
/*   Updated: 2017/11/05 14:17:41 by zadrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		list(char const *directory, t_ls **lst, int flags)
{
	int		nblock;
	DIR		*dir;

	// ft_putendl(directory);
	// ft_putendl("==============");
	if ((dir = opendir(directory)))
	{
		nblock = indir(dir, directory, lst, flags);
		closedir(dir);
		return (nblock);
	}
	else
		perror ("ft_ls");
	return (-1);
}

void	ft_lstfree(t_ls *lst)
{
	t_ls *tmp;

	while (lst != NULL)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp->path);
		free(tmp->name);
		free(tmp);
	}
}

void	ft_recursive(t_ls *lst, int flags)
{
	int		nblock;
	t_ls	*files;
	char	*tmp;

	while (lst)
	{
		if (ft_strcmp(lst->name, ".") != 0 && ft_strcmp(lst->name, "..") != 0)
			if (S_ISDIR(lst->buf.st_mode))
			{
				ft_putchar('\n');
				tmp = ft_strjoin(lst->path, "/");
				ft_putstr(lst->path);ft_putendl(":");
				nblock = list(tmp, &files, flags);
				if (nblock != -1)
				{
					if (flags & LOW_L_FLAG)
						ft_putstr("total ");ft_putnbr(nblock);ft_putchar('\n');
					print_file(&files, flags);
					ft_recursive(files, flags);
					free_lst(&files);
				}
				ft_strdel(&tmp);
			}
		lst = lst->next;
	}
}
