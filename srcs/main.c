/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zadrien <zadrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 13:46:13 by zadrien           #+#    #+#             */
/*   Updated: 2017/11/06 12:28:36 by zadrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

int		main(int ac, char **av)
{
	int		i;
	int		flags;
	t_ls	*dir;
	t_ls	*file;
	t_ls	*err;

	i = ac;
	flags = 0;
	if ((flags = return_flag(&i,  av)) != -1)
	{
		if (i != 1)
		{
			file = return_file(av + (ac - i + 1), flags, &err, &dir);
			err ? print_err(&err) : 0;
			file ? print_file(&file, flags) : 0;
			file && dir ? ft_putchar('\n') : 0;
			dir ? recup_indir(&dir, flags) : 0;
			dir ? free_lst(&dir) : 0;
			err ? free_lst(&err) : 0;
		}
		else
			lst_cur(flags);
	}
	return (0);
}
