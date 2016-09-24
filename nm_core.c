/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/05 16:42:01 by glasset           #+#    #+#             */
/*   Updated: 2016/09/24 20:44:35 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "nm.h"

char	type(int type, int sec, int value, t_flags *flags)
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
			if (sec == flags->text_nsect)
				c = 'T';
			else if (sec == flags->data_nsect)
				c = 'D';
			else if (sec == flags->bss_nsect)
				c = 'B';
			else
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

// TODO migrate to libft
int				ft_hexa(unsigned int n)
{
	unsigned int			a;
	unsigned int			u;
	char					*str;

	str = "0123456789abcdef";
	u = 0;
	a = n % 16;
	n = n / 16;
	if (n > 0)
		u = u + ft_hexa(n);
	write(1, &str[a], 1);
	u++;
	return (u);
}

void	print(int nsyms, int symoff, int stroff, char *ptr, t_flags *flags)
{
	int i;
	struct nlist_64		*list;
	char				*strtab;


	list = (void *) ptr + symoff;
	strtab = ptr + stroff;
	i = 0;

	while (i < nsyms)
	{
		// TODO clean print  + padding
		if (list[i].n_value) {
		ft_putstr("000000000000");
		ft_hexa(list[i].n_value);
		}
		else {
		ft_putstr("                ");
		}
		ft_putstr(" ");
		ft_putchar(type(list[i].n_type, list[i].n_sect, list[i].n_value, flags));
		ft_putstr(" ");
		ft_putendl(strtab + list[i++].n_un.n_strx);
	}
}

void	handle_segment(t_flags *flags, struct segment_command_64 *seg)
{
	int					i;
	struct section_64	*sec;

	i = 0;
	sec = (struct section_64 *) ((char *)seg + sizeof(struct segment_command_64));
	while (i < seg->nsects)
	{
		if (ft_strcmp((sec + i)->sectname, SECT_TEXT) == 0 &&
				ft_strcmp((sec + i)->segname, SEG_TEXT) == 0)
		{
			flags->text_nsect = i + 1;
		}
		else if (ft_strcmp((sec + i)->sectname, SECT_DATA) == 0 &&
				ft_strcmp((sec + i)->segname, SEG_DATA) == 0)
		{
			flags->data_nsect = i + 1;
		}
		else if (ft_strcmp((sec + i)->sectname, SECT_BSS) == 0 &&
				ft_strcmp((sec + i)->segname, SEG_DATA) == 0)
		{
			flags->bss_nsect = i + 1;
		}
		i++;
	}
}

void	header_64(char *ptr)
{
	t_flags					flags;
	struct mach_header_64	*header;
	struct load_command		*command;
	struct symtab_command	*sym;
	unsigned long int		i;
	int						ncmds;

	flags.text_nsect = NO_SECT;
	flags.data_nsect = NO_SECT;
	flags.bss_nsect = NO_SECT;
	i = 0;
	header = (struct mach_header_64 *)ptr;
	command = (void *)ptr + sizeof(*header);
	while (i < header->ncmds)
	{
		if (command->cmd == LC_SYMTAB)
		{
			sym = (struct symtab_command *)command;
			print(sym->nsyms, sym->symoff, sym->stroff, ptr, &flags);
			break;
		}
		if (command->cmd == LC_SEGMENT_64)
		{
			handle_segment(&flags, (struct segment_command_64 *)command);
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
