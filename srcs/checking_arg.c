/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zadrien <zadrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 13:48:32 by zadrien           #+#    #+#             */
/*   Updated: 2017/08/28 16:32:08 by zadrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

int		valid_opt(char c, int flag)
{
	int					i;
	static const t_opt	opt[5] = {{'a', LOW_A_FLAG}, {'l', LOW_L_FLAG},
								{'r', LOW_R_FLAG}, {'t', LOW_T_FLAG},
								{'R', UP_R_FLAG}};

	i = -1;
	while (++i < 5)
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
	ft_errormsg("usage:", NULL, " ft_ls -[arltR]");
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
		if (arg[i][1] != '-')
		{
			j = 0;
			while (arg[i][++j])
				if ((flag = valid_opt(arg[i][j], flag)) == -1)
					return (unvalid_opt(arg[i][j]));
			(*ac)--;
		}
		else
			break ;
	}
	return (flag);
}
