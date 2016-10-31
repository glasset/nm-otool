/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 23:03:20 by glasset           #+#    #+#             */
/*   Updated: 2016/10/31 22:04:03 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

int			get_len(char **sectnames)
{
	int		i;

	i = 0;
	while (sectnames[i] != NULL)
		i++;
	return (i);
}

static char	n_sect(char *sectname)
{
	char	c;

	c = '?';
	if (ft_strcmp(sectname, SECT_TEXT) == 0)
		c = 'T';
	else if (ft_strcmp(sectname, SECT_DATA) == 0)
		c = 'D';
	else if (ft_strcmp(sectname, SECT_BSS) == 0)
		c = 'B';
	else
		c = 'S';
	return (c);
}

char		type(int type, char *sectname, int value)
{
	char	c;
	int		t2;

	c = '?';
	t2 = type & N_TYPE;
	if (t2 == N_UNDF || t2 == N_PBUD)
	{
		if (value)
			c = 'C';
		else
			c = 'U';
	}
	else if (t2 == N_ABS)
		c = 'A';
	else if (t2 == N_SECT)
		c = n_sect(sectname);
	else if (t2 == N_INDR)
		c = 'I';
	if (!(type & N_EXT))
		c += 32;
	return (c);
}
/*
** lowercase (+32) => symbol is local (non-external)
*/
