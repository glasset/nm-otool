/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/05 16:42:01 by glasset           #+#    #+#             */
/*   Updated: 2016/10/19 14:33:29 by glasset          ###   ########.fr       */
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
			ft_putendl("FAT binary");
			break;
		case FAT_CIGAM:
			ft_putendl("FAT binary");
			break;
		default:
			ft_putendl("Unknown binary");
			break;
	}
	return 0;
}
