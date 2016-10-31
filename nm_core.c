/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/05 16:42:01 by glasset           #+#    #+#             */
/*   Updated: 2016/10/31 19:19:49 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

int		nm(char *ptr, char *filename)
{
	int	magic_number;

	magic_number = *(int *)ptr;
	if (magic_number == MH_MAGIC || magic_number == MH_CIGAM)
		header_32(ptr);
	else if (magic_number == MH_MAGIC_64 || magic_number == MH_CIGAM_64)
		header_64(ptr);
	else if (magic_number == FAT_MAGIC || magic_number == FAT_CIGAM)
		header_fat(ptr, filename);
	else
	{
		if (ft_strncmp(ptr, ARMAG, SARMAG) == 0)
			header_ar(ptr, filename);
		else
			ft_putstr("");
	}
	return (0);
}
