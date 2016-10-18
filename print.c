/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 22:40:55 by glasset           #+#    #+#             */
/*   Updated: 2016/10/18 23:03:16 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

static void		feedO(char **str)
{
	int i;

	i = 0;
	while (i < 16)
	{
		// TODO check 1 ?
		if (i == 7)
			(*str)[i] = '1';
		else
			(*str)[i] = '0';
		i++;
	}
	(*str)[i] = '\0';
}

int				ft_hexa(unsigned int n, char **str, int i)
{
	unsigned int			a;
	unsigned int			u;
	char					*val;

	feedO(str);
	val = "0123456789abcdef";
	u = 0;
	a = n % 16;
	n = n / 16;
	if (n > 0)
		u = u + ft_hexa(n, str, (i - 1));
	(*str)[i] =  val[a];
	u++;
	return (u);
}

void	print_list(t_print *cmd)
{
	cmd = to_start(cmd);
	while (cmd != NULL)
	{
		ft_putstr(cmd->hexa);
		ft_putstr(" ");
		ft_putchar(cmd->type);
		ft_putstr(" ");
		ft_putendl(cmd->name);
		cmd = cmd->next;
	}
}

int		is_sort(t_print *cmd)
{
	cmd = to_start(cmd);
	while (cmd->next != NULL)
	{
		if (ft_strcmp(cmd->name, cmd->next->name) > 0) {
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
