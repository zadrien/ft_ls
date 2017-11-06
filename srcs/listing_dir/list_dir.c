/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zadrien <zadrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 16:59:08 by zadrien           #+#    #+#             */
/*   Updated: 2017/11/06 01:20:34 by zadrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_timesort(t_ls **lst, t_ls *new, int flags)
{
	if ((flags & LOW_R_FLAG))
		ft_putsecrev(lst, new);
	else
		ft_putsec(lst, new);
}

void	ft_addata(t_ls **tmp, char *path, char *name)
{
	char	*tmp_path;
	if (!((*tmp) = (t_ls*)malloc(sizeof(t_ls))))
		return ;
	(*tmp)->next = NULL;
	(*tmp)->name = ft_strdup(name);
	(*tmp)->path = NULL;
	if (path[ft_strlen(path) - 1] != '/')
	{
		tmp_path = ft_strjoin(path, "/");
		(*tmp)->path = ft_strjoin(tmp_path, name);
		ft_strdel(&tmp_path);
	}
	else
		(*tmp)->path = ft_strjoin(path, name);
	// ft_putendl((*tmp)->path);

	if (lstat((*tmp)->path, &(*tmp)->buf))
	{
		perror("(ft_addata)--> lstat");
	}
}

int		indir(DIR *dir, char const *path, t_ls **files, int flags)
{
	t_ls			*tmp;
	int				nblock;
	struct dirent	*dirp;

	nblock = 0;
	if (!(*files = (t_ls*)malloc(sizeof(t_ls))))
		return (-1);
	(*files) = NULL;
	while ((dirp = readdir(dir)))
		if (!(!(flags & LOW_A_FLAG) && (dirp->d_name[0] == '.')))
		{
			ft_addata(&tmp, (char*)path, dirp->d_name);
			nblock += tmp->buf.st_blocks;
			if (flags & LOW_T_FLAG)
				ft_timesort(files, tmp, flags);
			else
				ft_asciisort(files, tmp, flags);
		}
	return (nblock);
}

void	lst_cur(int flags)
{
	int		nblock;
	DIR		*dir;
	t_ls	*files;

ft_putendl("??");
	if ((dir = opendir("./")))
	{
		if ((nblock = indir(dir, "./", &files, flags)) != -1)
		{
			if (flags & LOW_L_FLAG)
			{
				ft_putstr("total ");
				ft_putnbr(nblock);
				ft_putchar('\n');
			}
			print_file(&files, flags);
			if (flags & UP_R_FLAG)
				ft_recursive(files, flags);
			if (files)
				free_lst(&files);
		}
		closedir(dir);
	}
}

void	recup_indir(t_ls **dirs, int flags)
{
	t_ls	*tmp;
	t_ls	*files;
	DIR		*dir;
	int		nblock;

	files = NULL;
	if ((tmp = *dirs))
	{
		while (tmp)
		{
			nblock = 0;
			if ((dir = opendir(tmp->name)))
			{
				if ((nblock = indir(dir, tmp->name, &files, flags)) != -1)
				{
					if (flags & LOW_L_FLAG)
					{
						ft_putstr("total ");
						ft_putnbr(nblock);
						ft_putchar('\n');
					}
					print_file(&files, flags);
					if (flags & UP_R_FLAG)
					{
						ft_recursive(files, flags);
					}
					free_lst(&files);
				}
				closedir(dir);
			}
			else
				perror("ft_ls");
			if ((tmp = tmp->next))
				ft_putchar('\n');
		}
	}
}
