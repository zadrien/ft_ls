/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zadrien <zadrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 13:48:32 by zadrien           #+#    #+#             */
/*   Updated: 2017/11/06 12:13:26 by zadrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

int		valid_opt(char c, int flag)
{
	int					i;
	static const t_opt	opt[9] = {{'a', LOW_A_FLAG}, {'l', LOW_L_FLAG},
								{'r', LOW_R_FLAG}, {'t', LOW_T_FLAG},
								{'R', UP_R_FLAG}, {'G', UP_G_FLAG},
								{'T', UP_T_FLAG}, {'g', LOW_G_FLAG},
								{'o', LOW_O_FLAG}};

	i = -1;
	while (++i < 9)
		if (c == opt[i].opt)
			return (flag |= opt[i].flag);
	return (-1);
}

int		unvalid_opt(char c)
{
	ft_errormsg("ft_ls: ", "invalid option -- ", NULL);
	ft_putchar('\'');
	ft_putchar(c);
	ft_putendl("'");
	ft_errormsg("usage:", NULL, " ft_ls -[arltRTgG]");
	return (-1);
}

int		return_flag(int *ac, char **arg)
{
	int		i;
	int		j;
	int		flag;

	i = 0;
	flag = 0;
	while (arg[++i] && arg[i][0] == '-')
	{
		j = 0;
		if (ft_strcmp(arg[i], "--") == 0)
		{
			(*ac)--;
			break ;
		}
		while (arg[i][++j])
			if ((flag = valid_opt(arg[i][j], flag)) == -1)
				return (unvalid_opt(arg[i][j]));
		(*ac)--;
	}
	return (flag);
}
