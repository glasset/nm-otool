/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 22:43:32 by glasset           #+#    #+#             */
/*   Updated: 2016/10/18 22:59:38 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

t_print	*new_node(t_print *prev)
{
	t_print		*new;
	void		*tmp;

	if (!(new = (t_print *)malloc(sizeof(t_print))))
		return (NULL);
	if (!(tmp = malloc(sizeof(char) * 16 + 1)))
	{
		free(new);
		return (NULL);
	}
	new->hexa = (char *)tmp;
	new->type = 'U';
	new->name = NULL;
	new->next = NULL;
	new->prev = prev;

	return (new);
}

t_print *to_start(t_print *cmd)
{
	while (cmd->prev != NULL)
		cmd = cmd->prev;
	return cmd;
}
