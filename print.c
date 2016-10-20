/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 22:40:55 by glasset           #+#    #+#             */
/*   Updated: 2016/10/20 20:08:08 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

static void		feedO(char **str, int len)
{
	int i;

	i = 0;
	while (i < (len + 1))
	{
		(*str)[i++] = '0';
	}
	(*str)[i] = '\0';
}

static int		gen_hexa(unsigned long n, char **str, int i)
{
	unsigned int			a;
	unsigned int			u;
	char					*val;

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

int				ft_hexa(unsigned long n, char **str, int i)
{
	feedO(str, i);
	return (gen_hexa(n, str, i));
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
