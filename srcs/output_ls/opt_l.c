/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_l.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zadrien <zadrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 14:37:25 by zadrien           #+#    #+#             */
/*   Updated: 2017/11/06 12:13:00 by zadrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_stat(t_ls **file, int flags)
{
	struct passwd	*pwd;
	struct group	*grp;

	pwd = getpwuid((*file)->buf.st_uid);
	grp = getgrgid((*file)->buf.st_gid);
	ft_chmod((*file)->buf.st_mode);
	ft_putnbr((*file)->buf.st_nlink);
	ft_putchar(' ');
	if (!(flags & LOW_G_FLAG))
	{
		pwd ? ft_putstr(pwd->pw_name) : ft_putnbr((*file)->buf.st_uid);
		ft_putchar('\t');
	}
	if (!(flags & LOW_O_FLAG))
	{
		grp ? ft_putstr(grp->gr_name) : ft_putnbr((*file)->buf.st_gid);
		ft_putchar('\t');
	}
	ft_majminsize((*file)->buf.st_mode, (*file)->buf.st_rdev, (*file)->buf.st_size);
	ft_putchar('\t');
	ft_putstr(((*file)->time = ft_strsub(ctime(&(*file)->buf.st_mtime), 4, (flags & UP_T_FLAG) ? 20 : 12)));
	ft_putchar('\t');
	ft_namelst(*file, flags);
}

void	print_err(t_ls **err)
{
	t_ls	*tmp;

	if ((tmp = *err))
		while (tmp)
		{
			ft_errormsg("ft_ls: ", tmp->name, ": No such file of directory.");
			tmp = tmp->next;
		}
}

void	print_file(t_ls **file, int flags)
{
	t_ls		*tmp;

	if ((tmp = *file))
	{
		while (tmp)
		{
			if (flags & LOW_L_FLAG)
				print_stat(&tmp, flags);
			else
				ft_putendl(tmp->name);
			tmp = tmp->next;
		}
	}
}
