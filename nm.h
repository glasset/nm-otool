/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/05 14:52:19 by glasset           #+#    #+#             */
/*   Updated: 2016/08/05 17:02:01 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NM_H
# define NM_H
# define DEFAULT_OBJ "a.out"
# include <fcntl.h>
# include <ar.h>
# include <mach-o/ranlib.h>
# include <sys/stat.h>
# include <sys/mman.h>
# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <mach-o/fat.h>
# include <unistd.h>
//TODO clean include
#include <string.h>

int		nm(char *ptr);

#endif
