/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_files.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zadrien <zadrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 18:09:10 by zadrien           #+#    #+#             */
/*   Updated: 2017/02/05 15:30:06 by zadrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_namefiles(char *files, mode_t st_mode, int flags)
{
	if (S_ISLNK(st_mode))
		ft_linkedfiles(files, flags);
	else if (S_ISDIR(st_mode))
		ft_printcolors(files, DIRECTORY, flags, 1);
	else if (S_ISCHR(st_mode))
		ft_printcolors(files, CARACDEV, flags, 1);
	else
		ft_putendl(files);
}

void	ft_namefile(char *s, mode_t chmod, int flags)
{
	if (S_ISLNK(chmod))
		ft_printcolors(s, LINK, flags, 1);
	else if (S_ISDIR(chmod))
		ft_printcolors(s, DIRECTORY, flags, 1);
	else if (S_ISCHR(chmod))
		ft_printcolors(s, CARACDEV, flags, 1);
	else
		ft_putendl(s);
}

void	ft_printname(char *s, int flags)
{
	struct stat buf;

	if (lstat(s, &buf) != -1)
		ft_namefile(s, buf.st_mode, flags);
}

void	ft_linkedfiles(char *files, int flags)
{
	size_t	i;
	char	buf[1024];

	ft_bzero(buf, 1024);
	i = readlink(files, buf, 1024);
	ft_printcolors(files, LINK, flags, 0);
	ft_putstr(" -> ");
	ft_putendl(buf);
}

void	ft_filestat(char *s, int flags)
{
	struct stat		buf;
	struct passwd	*pwd;
	struct group	*grp;

	if (lstat(s, &buf) != -1)
	{
		pwd = getpwuid(buf.st_uid);
		grp = getgrgid(buf.st_gid);
		ft_chmod(buf.st_mode);
		ft_putnbrtab(buf.st_nlink);
		ft_putstrtab(pwd->pw_name);
		if (!(flags & LOW_O_FLAG))
			ft_putstrtab(grp->gr_name);
		ft_majminsize(buf.st_mode, buf.st_rdev, buf.st_size);
		ft_putchar('\t');
		if ((flags & UP_T_FLAG))
			ft_putstrtab(ft_strsub(ctime(&buf.st_mtime), 4, 20));
		else
			ft_putstrtab(ft_strsub(ctime(&buf.st_mtime), 4, 12));
		ft_namefiles(s, buf.st_mode, flags);
	}
}
