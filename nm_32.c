/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_32.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 11:19:58 by glasset           #+#    #+#             */
/*   Updated: 2016/10/31 22:07:15 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

static t_print				*generate_list(int nsyms, int symoff, int stroff,
		char *ptr, char **sectnames)
{
	int						i;
	struct nlist			*list;
	char					*strtab;
	t_print					*cmd;

	list = (void *)ptr + symoff;
	strtab = ptr + stroff;
	i = 0;
	cmd = new_node(NULL);
	while (i < nsyms)
	{
		if (list[i].n_value || (list[i].n_type & N_TYPE) == N_SECT)
			ft_hexa(list[i].n_value, &cmd->hexa, 7);
		else
			cmd->hexa = ft_strdup("        ");
		cmd->type = type(list[i].n_type, sectnames[list[i].n_sect - 1],
				list[i].n_value);
		cmd->name = ft_strdup(strtab + list[i++].n_un.n_strx);
		cmd->next = new_node(cmd);
		cmd = cmd->next;
	}
	cmd = cmd->prev;
	cmd->next = NULL;
	return (cmd);
}

static void					get_sectnames(struct segment_command *seg,
		char **sectnames)
{
	int						index;
	int						i;
	struct section			*sec;

	index = get_len(sectnames);
	i = 0;
	sec = (struct section *)((char *)seg + sizeof(struct segment_command));
	while (i < seg->nsects)
	{
		sectnames[index++] = (sec + i)->sectname;
		i++;
	}
	sectnames[index] = NULL;
}

void						header_32(char *ptr)
{
	struct mach_header		*header;
	struct load_command		*command;
	struct symtab_command	*sym;
	size_t					i;
	char					*sectnames[256];

	i = 0;
	sectnames[0] = NULL;
	header = (struct mach_header *)ptr;
	command = (void *)ptr + sizeof(*header);
	while (i < header->ncmds)
	{
		if (command->cmd == LC_SYMTAB)
		{
			sym = (struct symtab_command *)command;
		}
		if (command->cmd == LC_SEGMENT)
			get_sectnames((struct segment_command *)command, sectnames);
		command = (void *)command + command->cmdsize;
		i++;
	}
	sort(generate_list(sym->nsyms, sym->symoff, sym->stroff, ptr, sectnames));
}
