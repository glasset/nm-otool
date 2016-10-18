/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/05 14:52:19 by glasset           #+#    #+#             */
/*   Updated: 2016/10/18 23:08:53 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NM_H
# define NM_H
# define DEFAULT_OBJ "a.out"
# include <libft.h>
# include <fcntl.h>
# include <ar.h>
# include <mach-o/ranlib.h>
# include <sys/stat.h>
# include <sys/mman.h>
# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <mach-o/fat.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_flags {
	unsigned char	text_nsect;
	unsigned char	data_nsect;
	unsigned char	bss_nsect;
}					t_flags;

typedef struct				s_print {
	char					*hexa;
	char					type;
	char					*name;
	struct s_print			*next;
	struct s_print			*prev;
}							t_print;


int				nm(char *ptr);

/*
 * list
 */
t_print			*new_node(t_print *prev);
t_print			*to_start(t_print *cmd);

/*
 * print
 */
int		ft_hexa(unsigned int n, char **str, int i);
void	sort(t_print *cmd);


char	type(int type, int sec, int value, t_flags *flags);

#endif
