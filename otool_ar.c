/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_ar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 14:02:49 by glasset           #+#    #+#             */
/*   Updated: 2016/10/31 20:37:58 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

static void			putname(char *ar_name, char *obj_name)
{
	ft_putstr(ar_name);
	ft_putstr("(");
	ft_putstr(obj_name);
	ft_putstr("):\n");
}

static void			browse_ar(char *ptr, char *filename, size_t size, int *list)
{
	size_t			i;
	int				extended;
	struct ar_hdr	*ar;
	char			*str;

	i = 0;
	ar = (void*)ptr + SARMAG;
	extended = ft_atoi(ar->ar_name + ft_strlen(AR_EFMT1));
	while (i < size)
	{
		if (i != 0 && list[i -1]  == list[i])
		{
			i++;
			continue;
		}
		ar = (void*)ptr + list[i];
		str = ft_strdup(ft_strstr(ar->ar_name, ARFMAG) + ft_strlen(ARFMAG));
		putname(filename, str);
		otool((void*)ar + sizeof(*ar) + extended, str);
		i++;
	}
}

/*
** https://upload.wikimedia.org/wikipedia/commons/6/67/Deb_File_Structure.svg
*/
void				ot_ar(char *ptr, char *filename)
{
	struct ar_hdr	*ar;
	char			*str;
	size_t			size;
	int				extended;
	int				*list;

	ar = (void*)ptr + SARMAG;
	extended = ft_atoi(ar->ar_name + ft_strlen(AR_EFMT1));
	str = (void*)ptr + sizeof(*ar) + SARMAG + extended;
	size = *((int *)str);
	size /= sizeof(struct ranlib);
	list = sort_by_offset(gen_array((void*)str + 4, size, ptr), size);
	browse_ar(ptr, filename, size, list);
	free(list);
}
