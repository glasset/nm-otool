/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_ar.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 19:35:43 by glasset           #+#    #+#             */
/*   Updated: 2016/10/31 19:53:57 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

static int			is_sort(t_ar *rl, size_t len)
{
	int				i;

	i = 0;
	while ((i + 1) < len)
	{
		if (rl[i].ran_off > rl[i + 1].ran_off)
			return (0);
		i++;
	}
	return (1);
}

t_ar				*sort_by_offset(t_ar *arr, size_t len)
{
	t_ar			tmp;
	int				i;

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
				arr[i + 1] = tmp;
			}
			i++;
		}
	}
	return (arr);
}

t_ar				*gen_array(struct ranlib *rl, size_t len, char *ptr)
{
	struct ar_hdr	*ar;
	t_ar			*arr;
	int				i;

	arr = malloc(sizeof(arr) * len + 1);
	i = 0;
	while (i < len)
	{
		ar = (void*)ptr + rl[i].ran_off;
		arr[i].ran_off = rl[i].ran_off;
		// TODO bug bad alloc ?
		arr[i].name = ft_strdup(ft_strstr(ar->ar_name, ARFMAG) + ft_strlen(ARFMAG));
		i++;
	}
	return (arr);
}

