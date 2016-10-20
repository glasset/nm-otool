/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/05 16:42:01 by glasset           #+#    #+#             */
/*   Updated: 2016/10/19 20:14:47 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "nm.h"

int		nm(char *ptr)
{
	int	magic_number;

	magic_number = *(int *)ptr;
	switch (magic_number)
	{
		case MH_MAGIC:
			header_32(ptr);
			break;
		case MH_MAGIC_64:
			header_64(ptr);
			break;
		case MH_CIGAM_64: // TODO reverse little indian + handle CIGAM 32
			header_64(ptr);
			break;
		case FAT_MAGIC:
			header_fat(ptr);
			break;
		case FAT_CIGAM:
			header_fat(ptr);
			break;
		default:
			// TODO handle archive
			if (ft_strncmp(ptr, ARMAG, SARMAG) == 0)
				ft_putendl("ar");
			else
				ft_putendl("Unknown binary");
			break;
	}
	return 0;
}
