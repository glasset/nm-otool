/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_ar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 20:51:43 by glasset           #+#    #+#             */
/*   Updated: 2016/10/31 15:16:06 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

void				putname(char *ar_name, char *obj_name)
{
	ft_putchar('\n');
	ft_putstr(ar_name);
	ft_putstr("(");
	ft_putstr(obj_name);
	ft_putstr("):\n");
}

/*
** https://upload.wikimedia.org/wikipedia/commons/6/67/Deb_File_Structure.svg
** TODO 6 var
*/

void				header_ar(char *ptr, char *filename)
{
	struct ar_hdr	*ar;
	struct ranlib	*rl;
	char			*str;
	int				extended;
	int				size;
	int				i;

	i = 0;
	ar = (void*)ptr + SARMAG;
	extended = ft_atoi(ar->ar_name + ft_strlen(AR_EFMT1));
	str = (void*)ptr + sizeof(*ar) + SARMAG + extended;
	rl = (void*)str + 4;
	size = *((int *)str);
	size /= sizeof(struct ranlib);
	while (i < size)
	{
		ar = (void*)ptr + rl[i].ran_off;
		str = ft_strstr(ar->ar_name, ARFMAG) + ft_strlen(ARFMAG);
		putname(filename, str);
		nm((void*)ar + sizeof(*ar) + extended, str);
		i++;
	}
}
