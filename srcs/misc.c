/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zadrien <zadrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 18:11:12 by zadrien           #+#    #+#             */
/*   Updated: 2017/11/04 18:53:58 by zadrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	free_lst(t_ls **lst)
{
	t_ls	*tmp;

	while (*lst)
	{
		(*lst)->name ? ft_strdel(&(*lst)->name) : 0;
		(*lst)->path ? ft_strdel(&(*lst)->path) : 0;
		(*lst)->time ? ft_strdel(&(*lst)->time) : 0;
		tmp = *lst;
		*lst = (*lst)->next;
		tmp ? free(tmp) : 0;
	}
}
