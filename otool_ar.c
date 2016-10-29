/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_ar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 14:02:49 by glasset           #+#    #+#             */
/*   Updated: 2016/10/29 12:57:46 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

static int		is_sort(t_ar *rl, size_t len)
{
	int			i;

	i = 0;
	while ((i + 1) < len)
	{
		if (rl[i].ran_off > rl[i + 1].ran_off)
			return 0;
		i++;
	}
	return 1;
}

static t_ar			*gen_array(struct ranlib *rl, size_t len, char *ptr)
{
	struct ar_hdr	*ar;
	t_ar			*arr;
	int				i;

	arr = malloc(sizeof(arr) * len);
	i = 0;
	while (i < len)
	{
		ar = (void*)ptr + rl[i].ran_off;
		arr[i].ran_off = rl[i].ran_off;
		arr[i++].name = ft_strstr(ar->ar_name, ARFMAG) + ft_strlen(ARFMAG);
	}

	return arr;
}

static t_ar		*sort_by_offset(t_ar *arr, size_t len)
{
	t_ar		tmp;
	int			i;

	i = 0;
	while (!is_sort(arr, len))
	{
		i = 0;
		while ((i + 1) < len)
		{
			if (arr[i].ran_off > arr[i + 1].ran_off)
			{
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1]= tmp;
			}
			i++;
		}
	}
	return arr;
}

static void			putname(char *ar_name, char *obj_name)
{
	ft_putstr(ar_name);
	ft_putstr("(");
	ft_putstr(obj_name);
	ft_putstr("):\n");
}

/*
 * https://upload.wikimedia.org/wikipedia/commons/6/67/Deb_File_Structure.svg
 */
void			ot_ar(char *ptr, char *filename)
{
	struct ar_hdr	*ar;
	char			*str;
	int				i;
	int				size;
	int				extended;
	t_ar			*list;

	i = 0;
	ar = (void*)ptr + SARMAG;
	extended = ft_atoi(ar->ar_name + ft_strlen(AR_EFMT1));
	str = (void*)ptr + sizeof(*ar) + SARMAG + extended;
	size = *((int *)str);
	size /= sizeof(struct ranlib);
	list = sort_by_offset(gen_array((void*) str + 4, size, ptr), size);
	while (i < size){
		if (i == 0 || ((i - 1) >= 0 && list[i - 1].ran_off != list[i].ran_off)) // ignore doublon
		{
			ar = (void*)ptr + list[i].ran_off;
			putname(filename, list[i].name);
			otool((void*)ar + sizeof(*ar) + extended, list[i].name);
		}
		i++;
	}
	free(list);
}
