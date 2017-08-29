/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zadrien <zadrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 13:46:13 by zadrien           #+#    #+#             */
/*   Updated: 2017/08/28 16:43:58 by zadrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"


int		main(int ac, char **av)
{
	int		i;
	int		flags;
	t_arg	*dir;
	t_arg	*file;
	t_arg	*err;

	(void)ac;
	flags = 0;
	i = ac;
	if ((flags = return_flag(&i,  av)) != -1)
	{
		file = return_file(av + (ac - i + 1), flags, &err);
		dir = return_dir(av + (ac - i + 1), flags, &err);
		err ? print_err(&err) : 0;
		file ? print_file(&file, flags) : 0;
		dir ? recup_indir(&dir, flags) : 0;
	}
	return (0);
}
