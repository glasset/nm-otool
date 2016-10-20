/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_fat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 14:35:58 by glasset           #+#    #+#             */
/*   Updated: 2016/10/20 20:42:25 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"


int		reverse_int(int x)
{
	x = ((x << 8) & 0xFF00FF00) | ((x >> 8) & 0xFF00FF);
	return (x << 16) | (x >> 16);
}

void			header_fat(char *ptr)
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
		if (reverse_int(arch->cputype) == CPU_TYPE_X86_64 || reverse_int(arch->cputype) == CPU_TYPE_X86)
			offset = arch->offset;
		arch++;
		i++;
	}
	nm(ptr + reverse_int(offset));
}


