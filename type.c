/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 23:03:20 by glasset           #+#    #+#             */
/*   Updated: 2016/10/20 19:36:09 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "nm.h"

int		get_len(char **sectnames)
{
	int	i;

	i = 0;
	while (sectnames[i] != NULL)
		i++;
	return i;
}

static char n_sect(int type, char *sectname)
{
	char c;

	c = '?';
	if (ft_strcmp(sectname, SECT_TEXT) == 0)
		c = 'T';
	else if (ft_strcmp(sectname, SECT_DATA) == 0)
		c = 'D';
	else if (ft_strcmp(sectname, SECT_BSS) == 0)
		c = 'B';
	else {
		c = 'S';
	}
	return (c);
}

char	type(int type, char *sectname, int value)
{
	char	c;

	c = '?';
	switch (type & N_TYPE)
	{
		case N_UNDF:
		case N_PBUD:
			if (value)
				c = 'C';
			else
				c = 'U';
			break;
		case N_ABS:
			c = 'A';
			break;
		case N_SECT:
			c = n_sect(type, sectname);
			break;
		case N_INDR:
			c = 'I';
			break;
		default:
			break;
	}
	/*
	 * symbol is local (non-external)
	 */
	if (!(type & N_EXT))
		c += 32;

	return c;
}


