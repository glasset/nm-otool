/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/05 14:52:19 by glasset           #+#    #+#             */
/*   Updated: 2016/10/20 19:37:44 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NM_H
# define NM_H
# include <libft.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <ar.h>
# include <mach-o/ranlib.h>
# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <mach-o/fat.h>
# include <sys/stat.h>
# include <sys/mman.h>

# define DEFAULT_OBJ "a.out"

typedef struct				s_print {
	char					*hexa;
	char					type;
	char					*name;
	struct s_print			*next;
	struct s_print			*prev;
}							t_print;


int				nm(char *ptr);

void			header_64(char *ptr);
void			header_32(char *ptr);
void			header_fat(char *ptr);

/*
 * list
 */
t_print			*new_node(t_print *prev);
t_print			*to_start(t_print *cmd);

/*
 * print
 */
int		ft_hexa(unsigned long n, char **str, int i);
void	sort(t_print *cmd);


char	type(int type, char *sectname, int value);
int		get_len(char **sectnames);

#endif
