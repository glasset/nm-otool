/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_core.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 12:23:24 by glasset           #+#    #+#             */
/*   Updated: 2016/10/28 14:04:10 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

static void				print_addr(unsigned long n, int len, char suffix)
{
	char				*hexa;

	hexa = malloc(sizeof(char) * 16 + 1);
	ft_hexa(n, &hexa, len);
	ft_putstr(hexa);
	ft_putchar(suffix);
	free(hexa);
}

void				print_section(unsigned long addr, int size, char *ptr, int bit)
{
	size_t				i;

	i = 0;
	ft_putstr("Contents of (__TEXT,__text) section");
	while (i < size)
	{
		if (i % 16 == 0)
		{
			ft_putchar('\n');
			print_addr(addr, bit, '\t');
			addr += 16;
		}
		print_addr(ptr[i], 1, ' ');
		i++;
	}
	ft_putchar('\n');
}


int		otool(char *ptr, char * filename)
{
	int	magic_number;

	magic_number = *(int *)ptr;
	switch (magic_number)
	{
		case MH_MAGIC:
		case MH_CIGAM:
			ot_32(ptr);
			break;
		case MH_MAGIC_64:
		case MH_CIGAM_64: // TODO reverse little indian + handle CIGAM 32
			ot_64(ptr);
			break;
		case FAT_MAGIC:
		case FAT_CIGAM:
			ot_fat(ptr, filename);
			break;
		default:
			if (ft_strncmp(ptr, ARMAG, SARMAG) == 0)
				ot_ar(ptr, filename);
			else
				ft_putendl("Unknown binary");
			break;
	}
	return (0);
}
