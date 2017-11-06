/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chmod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zadrien <zadrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 11:10:11 by zadrien           #+#    #+#             */
/*   Updated: 2017/11/04 16:30:33 by zadrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	ft_stickybit(mode_t chmod, int i)
{
	if (i == 1)
		if ((chmod & S_ISUID))
			return ('s');
	if (i == 2)
		if ((chmod & S_ISGID))
			return ('s');
	if (i == 3)
		if ((chmod & S_ISVTX))
			return ('t');
	return ('x');
}

char	stickmaj(mode_t chmod, int i)
{
	if (i == 1)
		if ((chmod & S_ISUID))
			return ('S');
	if (i == 2)
		if ((chmod & S_ISGID))
			return ('S');
	if (i == 3)
		if ((chmod & S_ISVTX))
			return ('T');
	return ('-');
}

char	ft_typeofile(mode_t chmod)
{
	if (S_ISDIR(chmod))
		return ('d');
	else if (S_ISLNK(chmod))
		return ('l');
	else if (S_ISCHR(chmod))
		return ('c');
	else if (S_ISBLK(chmod))
		return ('b');
	else if (S_ISFIFO(chmod))
		return ('p');
	else if (S_ISSOCK(chmod))
		return ('s');
	else
		return ('-');
}

void	ft_chmod(mode_t chmod)
{
	ft_putchar(ft_typeofile(chmod));
	ft_putchar((chmod & S_IRUSR) ? 'r' : '-');
	ft_putchar((chmod & S_IWUSR) ? 'w' : '-');
	ft_putchar((chmod & S_IXUSR) ? ft_stickybit(chmod, 1) : stickmaj(chmod, 1));
	ft_putchar((chmod & S_IRGRP) ? 'r' : '-');
	ft_putchar((chmod & S_IWGRP) ? 'w' : '-');
	ft_putchar((chmod & S_IXGRP) ? ft_stickybit(chmod, 2) : stickmaj(chmod, 2));
	ft_putchar((chmod & S_IROTH) ? 'r' : '-');
	ft_putchar((chmod & S_IWOTH) ? 'w' : '-');
	ft_putchar((chmod & S_IXOTH) ? ft_stickybit(chmod, 3) : stickmaj(chmod, 3));
	ft_putchar(' ');
}
