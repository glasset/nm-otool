/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_ar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 20:51:43 by glasset           #+#    #+#             */
/*   Updated: 2016/10/20 21:36:48 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

void			header_ar(char *ptr, char *filename)
{
	ft_putstr("\n");
	ft_putstr(filename);
	ft_putstr("(");
	ft_putstr("?");
	ft_putendl("):");
}
