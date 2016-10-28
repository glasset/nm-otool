/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_64.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 12:29:45 by glasset           #+#    #+#             */
/*   Updated: 2016/10/28 13:57:54 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

static void				get_sectnames(struct segment_command_64 *seg, struct mach_header_64	*header)
{
	size_t				i;
	struct section_64	*sec;

	i = 0;
	sec = (struct section_64 *) ((char *)seg + sizeof(struct segment_command_64));
	while (i < seg->nsects)
	{
		if (ft_strcmp((sec + i)->sectname, SECT_TEXT) == 0 &&
				ft_strcmp((sec + i)->segname, SEG_TEXT) == 0)
		{
			print_section((sec + i)->addr, (sec + i)->size, (char *)header + (sec + i)->offset, 15);
		}
		i++;
	}
}

void	ot_64(char *ptr)
{
	struct mach_header_64	*header;
	struct load_command		*command;
	struct symtab_command	*sym;
	unsigned long int		i;
	int						ncmds;

	i = 0;
	header = (struct mach_header_64 *)ptr;
	command = (void *)ptr + sizeof(*header);
	while (i < header->ncmds)
	{
		if (command->cmd == LC_SEGMENT_64)
			get_sectnames((struct segment_command_64 *)command, header);
		command = (void *)command + command->cmdsize;
		i++;
	}
}
