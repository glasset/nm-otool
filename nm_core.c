/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/05 16:42:01 by glasset           #+#    #+#             */
/*   Updated: 2016/10/20 21:13:26 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "nm.h"

int		nm(char *ptr, char *filename)
{
	int	magic_number;

	magic_number = *(int *)ptr;
	switch (magic_number)
	{
		case MH_MAGIC:
		case MH_CIGAM:
			header_32(ptr);
			break;
		case MH_MAGIC_64:
		case MH_CIGAM_64: // TODO reverse little indian + handle CIGAM 32
			header_64(ptr);
			break;
		case FAT_MAGIC:
		case FAT_CIGAM:
			header_fat(ptr, filename);
			break;
		default:
			if (ft_strncmp(ptr, ARMAG, SARMAG) == 0)
				header_ar(ptr, filename);
			else
				ft_putendl("Unknown binary");
			break;
	}
	return 0;
}
