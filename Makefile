#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: glasset <glasset@student.42.fr>            +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/08/05 14:53:35 by glasset           #+#    #+#             *#
#*   Updated: 2016/09/09 12:10:38 by glasset          ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NM = ft_nm

OTOOL = ft_otool

SRC_NM = ft_nm.c \
		 nm_core.c

SRC_OTOOL = ft_otool.c

OBJ_NM = $(SRC_NM:.c=.o)

OBJ_OTOOL = $(SRC_OTOOL:.c=.o)

COMPILER=gcc
COMPILER_FLAGS = -Wall -Wextra -Werror

all: $(NM) $(OTOOL)

$(NM): $(OBJ_NM)
	@make -C libft
	@$(COMPILER) $(OBJ_NM) -L libft -lft -o $(NM)

$(OTOOL): $(OBJ_OTOOL)
	@$(COMPILER) $(OBJ_OTOOL) -L libft -lft -o $(OTOOL)

%.o: %.c
	@$(COMPILER) $(FLAGS) -c -I libft/ $<

clean:
	@rm -f $(OBJ_NM)
	@rm -f $(OBJ_OTOOL)
	@make -C libft/ clean

fclean: clean
	@rm -f $(NM)
	@rm -f $(OTOOL)
	@make -C libft/ fclean

re: fclean all
