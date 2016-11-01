/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 22:40:55 by glasset           #+#    #+#             */
/*   Updated: 2016/11/01 12:10:55 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

void	print_list(t_print *cmd)
{
	cmd = to_start(cmd);
	while (cmd != NULL)
	{
		if (cmd->type != 'w')
		{
			ft_putstr(cmd->hexa);
			ft_putchar(' ');
			ft_putchar(cmd->type);
			ft_putchar(' ');
			ft_putendl(cmd->name);
		}
		cmd = cmd->next;
	}
}

int		is_sort(t_print *cmd)
{
	cmd = to_start(cmd);
	while (cmd->next != NULL)
	{
		if (ft_strcmp(cmd->name, cmd->next->name) > 0)
		{
			return (0);
		}
		cmd = cmd->next;
	}
	return (1);
}

void	sort(t_print *cmd)
{
	t_print *tmp;

	tmp = NULL;
	while (is_sort(cmd) == 0)
	{
		cmd = to_start(cmd);
		while (cmd->next != NULL)
		{
			if (ft_strcmp(cmd->name, cmd->next->name) > 0)
			{
				tmp = cmd;
				cmd = cmd->next;
				cmd->prev = tmp->prev;
				if (tmp->prev != NULL)
					tmp->prev->next = cmd;
				tmp->prev = cmd;
				tmp->next = cmd->next;
				if (tmp->next != NULL)
					tmp->next->prev = tmp;
				cmd->next = tmp;
			}
			cmd = cmd->next;
		}
	}
	print_list(cmd);
}
