/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zadrien <zadrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 13:46:47 by zadrien           #+#    #+#             */
/*   Updated: 2017/11/05 14:53:05 by zadrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <dirent.h>
# include "../libft/libft.h"
# define _BSD_SOURCE
# define _XOPEN_SOURCE 700
# define _DARWIN_C_SOURCE

# define LOW_A_FLAG 1
# define LOW_L_FLAG 2
# define LOW_R_FLAG 4
# define UP_R_FLAG 8
# define LOW_T_FLAG 16
# define UP_G_FLAG 32
# define UP_T_FLAG 64
# define LOW_O_FLAG 128
# define LOW_S_FLAG 256
# define LOW_G_FLAG 512

# define EXEC               "\x1b[31m"
# define BLOCKDEV           "\x1b[32m"
# define CARACDEV           "\x1b[33m"
# define LINK               "\x1b[35m"
# define DIRECTORY          "\x1b[36m"
# define ANSI_COLOR_RESET   "\x1b[0m"

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

typedef struct		s_ls
{
	char			*name;
	char			*path;
	char			*time;
	struct stat		buf;
	struct s_ls		*next;
}					t_ls;

int		return_flag(int *ac, char **arg);
int		unvalid_opt(char c);
int		valid_opt(char c, int flag);
t_ls	*return_file(char **av, int flags, t_ls **err, t_ls **dir);

/*
********************************************************************************
**                              PRINT FUNCTION                                **
********************************************************************************
*/
void	ft_chmod(mode_t chmod);
void	ft_majminsize(mode_t chmod, dev_t dev, off_t size);
void	ft_namelst(t_ls *lst, int flags);
void	print_file(t_ls **file, int flags);
void	print_stat(t_ls **file, int flags);
void	print_err(t_ls **err);


/*
********************************************************************************
**                              SORT DIRECTORY                                **
********************************************************************************
*/
void	lst_cur(int flags);
void	recup_indir(t_ls **dirs, int flags);
int		indir(DIR *dir, char const *path, t_ls **files, int flags);
void	ft_addata(t_ls **tmp, char *path, char *name);
void	ft_timesort(t_ls **lst, t_ls *new, int flags);
void	ft_lstcmp(t_ls **lst, t_ls *new);
void	ft_lstrevcmp(t_ls **lst, t_ls *new);
void	ft_asciisort(t_ls **lst, t_ls *new, int flags);
int		ft_addnode(t_ls **lst, t_ls *node);
void	ft_addhead(t_ls **lst, t_ls *new);
void	ft_putsec(t_ls **lst, t_ls *n);
void	ft_putsecrev(t_ls **lst, t_ls *n);
void	ft_addbetween(t_ls **lst, t_ls *n, t_ls *beg, t_ls *pre);
void	ft_recursive(t_ls *lst, int flags);
void	free_lst(t_ls **lst);
#endif
