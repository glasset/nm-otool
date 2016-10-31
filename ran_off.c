/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ran_off.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 19:35:43 by glasset           #+#    #+#             */
/*   Updated: 2016/10/31 20:30:42 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

static int			is_sort(int *rl, size_t len)
{
	int				i;

	i = 0;
	while ((i + 1) < len)
	{
		if (rl[i] > rl[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int					*sort_by_offset(int *arr, size_t len)
{
	int				tmp;
	int				i;

	i = 0;
	while (!is_sort(arr, len))
	{
		i = 0;
		while ((i + 1) < len)
		{
			if (arr[i] > arr[i + 1])
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

int					*gen_array(struct ranlib *rl, size_t len, char *ptr)
{
	struct ar_hdr	*ar;
	int				*arr;
	int				i;

	arr = malloc(sizeof(arr) * len + 1);
	ft_bzero(arr, len);
	i = 0;
	while (i < len)
	{
		ar = (void*)ptr + rl[i].ran_off;
		arr[i] = rl[i].ran_off;
		i++;
	}
	return (arr);
}
