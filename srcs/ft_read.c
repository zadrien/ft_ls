/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zadrien <zadrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 16:18:26 by zadrien           #+#    #+#             */
/*   Updated: 2017/02/05 18:27:42 by zadrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_namelst(t_pain *lst, mode_t st_mode, off_t st_size, int flags)
{
	if (S_ISLNK(st_mode))
		ft_linkedfile(lst, st_size, flags);
	else if (S_ISDIR(st_mode))
		ft_printcolors(lst->name, DIRECTORY, flags, 1);
	else if (S_ISCHR(st_mode))
		ft_printcolors(lst->name, CARACDEV, flags, 1);
	else if (S_ISBLK(st_mode))
		ft_printcolors(lst->name, BLOCKDEV, flags, 1);
	else if ((st_mode & S_IXUSR))
		ft_printcolors(lst->name, EXEC, flags, 1);
	else
		ft_putendl(lst->name);
}

void	ft_stat(t_pain *lst, int flags)
{
	struct stat		buf;
	struct passwd	*pwd;
	struct group	*grp;

	if (lstat(lst->path, &buf) != -1)
	{
		pwd = getpwuid(buf.st_uid);
		grp = getgrgid(buf.st_gid);
		ft_chmod(buf.st_mode);
		ft_putnbrtab(buf.st_nlink);
		if (!(flags & LOW_G_FLAG))
			pwd ? ft_putstrtab(pwd->pw_name) : ft_putnbrtab(buf.st_uid);
		if (!(flags & LOW_O_FLAG))
			ft_putstrtab(grp->gr_name);
		ft_majminsize(buf.st_mode, buf.st_rdev, buf.st_size);
		ft_putchar('\t');
		if ((flags & UP_T_FLAG))
			ft_putstrtab(ft_strsub(ctime(&buf.st_mtime), 4, 20));
		else
			ft_putstrtab(ft_strsub(ctime(&buf.st_mtime), 4, 12));
		ft_namelst(lst, buf.st_mode, buf.st_size, flags);
	}
}

void	ft_withoutl(t_pain *lst, int flags)
{
	struct stat buf;

	if (lstat(lst->name, &buf) != -1 && (flags & LOW_C_FLAG))
	{
		if (S_ISLNK(buf.st_mode))
			ft_printcolors(lst->name, LINK, flags, 1);
		else if (S_ISDIR(buf.st_mode))
			ft_printcolors(lst->name, DIRECTORY, flags, 1);
		else if (S_ISCHR(buf.st_mode))
			ft_printcolors(lst->name, CARACDEV, flags, 1);
		else if (S_ISBLK(buf.st_mode))
			ft_printcolors(lst->name, BLOCKDEV, flags, 1);
		else if ((buf.st_mode & S_IXUSR))
			ft_printcolors(lst->name, EXEC, flags, 1);
		else
			ft_putendl(lst->name);
	}
	else
		ft_putendl(lst->name);
}

void	ft_read(t_pain *lst, int flags)
{
	while (lst)
	{
		if ((flags & LOW_L_FLAG))
			ft_stat(lst, flags);
		else
			ft_withoutl(lst, flags);
		lst = lst->next;
	}
}

void	ft_readtype(t_pain *lst, int flags, int ac)
{
	if (!lst)
	{
		ft_putchar('\n');
		return ;
	}
	ft_read(lst, flags);
	if (ac > 1)
		ft_putchar('\n');
}
