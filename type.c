/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 23:03:20 by glasset           #+#    #+#             */
/*   Updated: 2016/10/19 14:29:55 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "nm.h"

static char n_sect(int type, int sec, t_flags *flags)
{
	char c;

	c = '?';
	if (sec == flags->text_nsect)
		c = 'T';
	else if (sec == flags->data_nsect)
		c = 'D';
	else if (sec == flags->bss_nsect)
		c = 'B';
	else
		c = 'S';
	return (c);
}

char	type(int type, int sec, int value, t_flags *flags)
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
			c = n_sect(type, sec, flags);
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


