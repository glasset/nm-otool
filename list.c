/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 22:43:32 by glasset           #+#    #+#             */
/*   Updated: 2016/11/01 12:25:35 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

t_print	*new_node(t_print *prev)
{
	t_print		*new;

	if (!(new = (t_print *)malloc(sizeof(t_print))))
		return (NULL);
	new->hexa = ft_strdup("                ");
	new->type = 'U';
	new->name = NULL;
	new->next = NULL;
	new->prev = prev;
	return (new);
}

t_print	*to_start(t_print *cmd)
{
	while (cmd->prev != NULL)
		cmd = cmd->prev;
	return (cmd);
}
