/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_fat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 13:58:09 by glasset           #+#    #+#             */
/*   Updated: 2016/10/31 15:07:46 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

int						reverse_int(int x)
{
	x = ((x << 8) & 0xFF00FF00) | ((x >> 8) & 0xFF00FF);
	return (x << 16) | (x >> 16);
}

void					ot_fat(char *ptr, char *filename)
{
	struct fat_header	*header;
	struct fat_arch		*arch;
	int					i;
	int					offset;

	i = 0;
	header = (void *)ptr;
	arch = (void *)ptr + sizeof(header);
	while (i < reverse_int(header->nfat_arch))
	{
		if (reverse_int(arch->cputype) == CPU_TYPE_X86_64
				|| reverse_int(arch->cputype) == CPU_TYPE_X86)
			offset = arch->offset;
		arch++;
		i++;
	}
	otool(ptr + reverse_int(offset), filename);
}
