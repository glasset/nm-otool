/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_32.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 13:53:59 by glasset           #+#    #+#             */
/*   Updated: 2016/10/28 14:02:09 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

static void				get_sectnames(struct segment_command *seg, struct mach_header	*header)
{
	size_t				i;
	struct section	*sec;

	i = 0;
	sec = (struct section *) ((char *)seg + sizeof(struct segment_command));
	while (i < seg->nsects)
	{
		if (ft_strcmp((sec + i)->sectname, SECT_TEXT) == 0 &&
				ft_strcmp((sec + i)->segname, SEG_TEXT) == 0)
		{
			print_section((sec + i)->addr, (sec + i)->size, (char *)header + (sec + i)->offset, 7);
		}
		i++;
	}
}

void	ot_32(char *ptr)
{
	struct mach_header	*header;
	struct load_command		*command;
	struct symtab_command	*sym;
	unsigned long int		i;
	int						ncmds;

	i = 0;
	header = (struct mach_header *)ptr;
	command = (void *)ptr + sizeof(*header);
	while (i < header->ncmds)
	{
		if (command->cmd == LC_SEGMENT)
			get_sectnames((struct segment_command *)command, header);
		command = (void *)command + command->cmdsize;
		i++;
	}
}

