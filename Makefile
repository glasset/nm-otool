#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: glasset <glasset@student.42.fr>            +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/08/05 14:53:35 by glasset           #+#    #+#             *#
#*   Updated: 2016/08/05 17:04:16 by glasset          ###   ########.fr       *#
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
	@$(COMPILER) $(OBJ_NM) -o $(NM)

$(OTOOL): $(OBJ_OTOOL)
	@$(COMPILER) $(OBJ_OTOOL) -o $(OTOOL)

%.o: %.c
	@$(COMPILER) $(FLAGS) -c $<

clean:
	@rm -f $(OBJ_NM)
	@rm -f $(OBJ_OTOOL)

fclean: clean
	@rm -f $(NM)
	@rm -f $(OTOOL)

re: fclean all
