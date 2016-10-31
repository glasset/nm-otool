/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/05 14:52:19 by glasset           #+#    #+#             */
/*   Updated: 2016/10/31 19:41:55 by glasset          ###   ########.fr       */
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

typedef struct		s_print {
	char			*hexa;
	char			type;
	char			*name;
	struct s_print	*next;
	struct s_print	*prev;
}					t_print;

typedef struct		s_ar
{
	uint32_t		ran_off;
	char			*name;
}					t_ar;

int					nm(char *ptr, char *filename);

void				header_64(char *ptr);
void				header_32(char *ptr);
void				header_fat(char *ptr, char *filename);
void				header_ar(char *ptr, char *filename);

/*
** list & t_ar managment
*/
t_print				*new_node(t_print *prev);
t_print				*to_start(t_print *cmd);
t_ar				*sort_by_offset(t_ar *arr, size_t len);
t_ar				*gen_array(struct ranlib *rl, size_t len, char *ptr);


/*
** print & list
*/
void				sort(t_print *cmd);
char				type(int type, char *sectname, int value);
int					get_len(char **sectnames);

int					ft_hexa(unsigned long n, char **str, int i);

/*
** otool
*/
int					otool(char *ptr, char *filename);
void				ot_64(char *ptr);
void				ot_32(char *ptr);
void				ot_fat(char *ptr, char *filename);
void				ot_ar(char *ptr, char *filename);

void				print_section(unsigned long addr, int size, char *ptr,
		int bit);

#endif
