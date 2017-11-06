/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zadrien <zadrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 15:48:47 by zadrien           #+#    #+#             */
/*   Updated: 2017/11/04 18:10:17 by zadrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void	ft_majminsize(mode_t chmod, dev_t dev, off_t size)
{
	if (S_ISCHR(chmod))
	{
		ft_putnbroct(major(dev));
		ft_putstr(",  ");
		ft_putnbroct(minor(dev));
	}
	else
		ft_putnbr(size);
}

void	ft_printcolors(char *name, char *colors, int flags, int i)
{
	if ((flags & UP_G_FLAG))
	{
		ft_putstr(colors);
		ft_putstr(name);
		ft_putstr(ANSI_COLOR_RESET);
	}
	else
		ft_putstr(name);
	if (i == 1)
		ft_putchar('\n');
}

void	ft_linkedfile(t_ls *lst, off_t st_size, int flags)
{
	char	buf[1024];

	ft_bzero(buf, 1024);
	readlink((lst->path ? lst->path : lst->name), buf, (st_size > 0 ? st_size + 1 : 1024));
	ft_printcolors(lst->name, LINK, flags, 0);
	ft_putstr(" -> ");
	ft_putendl(buf);
}

void	ft_namelst(t_ls *lst, int flags)
{
	if (flags & UP_G_FLAG)
	{
		if (S_ISLNK(lst->buf.st_mode))
			ft_linkedfile(lst, lst->buf.st_size, flags);
		else if (S_ISDIR(lst->buf.st_mode))
			ft_printcolors(lst->name, DIRECTORY, flags, 1);
		else if (S_ISCHR(lst->buf.st_mode))
			ft_printcolors(lst->name, CARACDEV, flags, 1);
		else if (S_ISBLK(lst->buf.st_mode))
			ft_printcolors(lst->name, BLOCKDEV, flags, 1);
		else if ((lst->buf.st_mode & S_IXUSR))
			ft_printcolors(lst->name, EXEC, flags, 1);
		else
			ft_putendl(lst->name);
	}
	else if (S_ISLNK(lst->buf.st_mode))
		ft_linkedfile(lst, lst->buf.st_size, flags);
	else
		ft_putendl(lst->name);
}
