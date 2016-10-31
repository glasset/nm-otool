/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 12:57:10 by glasset           #+#    #+#             */
/*   Updated: 2016/10/31 14:52:56 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

static void		init(char **str, int len)
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
		u = u + gen_hexa(n, str, (i - 1));
	(*str)[i] = val[a];
	u++;
	return (u);
}

int				ft_hexa(unsigned long n, char **str, int i)
{
	init(str, i);
	return (gen_hexa(n, str, i));
}
