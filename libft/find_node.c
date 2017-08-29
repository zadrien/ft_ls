/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zadrien <zadrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 08:36:50 by zadrien           #+#    #+#             */
/*   Updated: 2017/05/16 06:16:21 by zadrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_env	*find_node(t_env **env, char *var, char *value)
{
	t_env	*tmp;

	tmp = *env;
	if (var != NULL)
		while (tmp && ft_strcmp(tmp->var, var) != 0)
			tmp = tmp->next;
	else
		while (tmp && ft_strcmp(tmp->value, value) != 0)
			tmp = tmp->next;
	return (tmp);
}
