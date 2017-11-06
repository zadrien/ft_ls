/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zadrien <zadrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 16:09:52 by zadrien           #+#    #+#             */
/*   Updated: 2017/02/05 16:14:58 by zadrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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
	if ((flags & LOW_C_FLAG))
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

void	ft_total(int block)
{
	ft_putstr("total ");
	ft_putendn(block);
}

void	ft_readatfile(char *s, int flags)
{
	if ((flags & LOW_L_FLAG))
		ft_filestat(s, flags);
	else
		ft_printname(s, flags);
}

void	ft_linkedfile(t_pain *lst, off_t st_size, int flags)
{
	size_t	i;
	char	buf[1024];

	ft_bzero(buf, 1024);
	i = readlink(lst->path, buf, st_size > 0 ? st_size + 1 : 1024);
	ft_printcolors(lst->name, LINK, flags, 0);
	ft_putstr(" -> ");
	ft_putendl(buf);
}
