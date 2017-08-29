/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zadrien <zadrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 13:46:47 by zadrien           #+#    #+#             */
/*   Updated: 2017/08/28 16:45:45 by zadrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include "../libft/libft.h"
# define LOW_A_FLAG 1
# define LOW_L_FLAG 2
# define LOW_R_FLAG 4
# define LOW_T_FLAG 8
# define UP_R_FLAG 16

typedef struct s_opt
{
	char		opt;
	int			flag;
}				t_opt;

typedef struct s_opte
{
	int			opt;
	char		*str;
}				t_opte;

typedef struct	s_arg
{
	char			*arg;
	int				type;
	struct s_arg	*next;
}				t_arg;

typedef struct 	s_lst
{
	char		*name;
	char		*path;

}				t_lst;

int		return_flag(int *ac, char **arg);
int		unvalid_opt(char c);
int		valid_opt(char c, int flag);
#endif
