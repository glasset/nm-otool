#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: glasset <glasset@student.42.fr>            +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/08/05 14:53:35 by glasset           #+#    #+#             *#
#*   Updated: 2016/10/20 20:51:59 by glasset          ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NM = ft_nm

OTOOL = ft_otool

SRC_NM = ft_nm.c \
		 nm_core.c \
		 nm_64.c \
		 nm_32.c \
		 nm_fat.c \
		 nm_ar.c \
		 list.c \
		 print.c \
		 type.c

SRC_OTOOL = ft_otool.c

OBJ_NM = $(SRC_NM:.c=.o)

OBJ_OTOOL = $(SRC_OTOOL:.c=.o)

COMPILER=gcc
COMPILER_FLAGS = -Wall -Wextra -Werror

all: $(NM) $(OTOOL)

$(NM): $(OBJ_NM)
	@make -C libft
	@$(COMPILER) $(OBJ_NM) -L libft -lft -o $(NM)
	@echo $(NM) compil

$(OTOOL): $(OBJ_OTOOL)
	@$(COMPILER) $(OBJ_OTOOL) -L libft -lft -o $(OTOOL)
	@echo $(OTOOL) compil

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
