/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/05 16:42:01 by glasset           #+#    #+#             */
/*   Updated: 2016/09/18 17:49:06 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "nm.h"

char	type(int type, int sec, int value)
{
	char	c;
	c = '?';
	switch (type & N_TYPE)
	{
		case N_UNDF:
		case N_PBUD:
			if (value)
				c = 'C';
			else
				c = 'U';
			break;
		case N_ABS:
			c = 'A';
			break;
		case N_SECT:
	//		if (sec == flags->text_nsect) TODO plug struct
	//			c = 'T';
	//		else if (sec == flags->data_nsect)
	//			c = 'D';
	//		else if (sec == flags->bss_nsect)
	//			c = 'B';
	//		else
				c = 'S';
			break;
		case N_INDR:
			c = 'I';
			break;
		default:
			break;
	}

	return c;
}

void	print(int nsyms, int symoff, int stroff, char *ptr)
{
	int i;
	struct nlist_64		*list;
	char				*strtab;


	list = (void *) ptr + symoff;
	strtab = ptr + stroff;
	i = 0;

	while (i < nsyms)
	{
		ft_putnbr(list[i].n_value);
		ft_putstr("\t");
		ft_putchar(type(list[i].n_type, list[i].n_sect, list[i].n_value));
		ft_putstr("\t");
		ft_putendl(strtab + list[i++].n_un.n_strx);
	}
}

void	header_64(char *ptr)
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
		if (command->cmd == LC_SYMTAB)
		{
			sym = (struct symtab_command *)command;
			print(sym->nsyms, sym->symoff, sym->stroff, ptr);
			 // TODO  clean / print
			break;
		}
		command = (void *)command + command->cmdsize;
		i++;
	}
}


int		nm(char *ptr)
{
	int	magic_number;

	magic_number = *(int *)ptr;
	switch (magic_number)
	{
		case MH_MAGIC_64:
			header_64(ptr);
			break;
		case MH_CIGAM_64: // TODO reverse little indian
			header_64(ptr);
			break;
		case FAT_MAGIC:
			break;
		case FAT_CIGAM:
			break;
		default:
			ft_putendl("Unknown binary");
			break;
	}
	return 0;
}
