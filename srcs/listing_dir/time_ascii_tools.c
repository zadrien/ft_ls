/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_ascii_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zadrien <zadrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 17:15:22 by zadrien           #+#    #+#             */
/*   Updated: 2017/11/04 17:20:23 by zadrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_timesort(t_ls **lst, t_ls *new, int flags)
{
	if ((flags & LOW_R_FLAG))
		ft_putsecrev(lst, new);
	else
		ft_putsec(lst, new);
}
