# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/08 20:31:12 by erpiana           #+#    #+#              #
#    Updated: 2024/05/14 02:57:16 by erpiana          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#******************************************************************************#
#                                   PATH                                       #
#******************************************************************************#

SRC_P            := srcs/
LIB_P            := libft/
INCS             := include/ $(LIB_P)include/
CPPFLAGS         := $(addprefix -I, $(INCS)) -MP

#******************************************************************************#
#                                  FILES                                       #
#******************************************************************************#

SRCS     += $(addprefix $(SRC_P), main.c ft_parse_arguments.c ft_utils.c \
			ft_utils_list.c init.c push.c reverse_rotatate.c\
			rotatate.c swap.c push_swap.c linked_list_aux.c index.c cost.c \
			operations.c position.c update.c)
OBJS     += $(addprefix obj/, $(notdir $(SRCS:.c=.o)))
NAME     := push_swap
LIBFT    := $(addprefix $(LIB_P), libft.a)

#******************************************************************************#
#                               BASH COMMANDS                                  #
#******************************************************************************#

RM          := rm -rf
BUILD       := obj/

#******************************************************************************#
#                                COMPILATION                                   #
#******************************************************************************#

CC       := cc
CFLAGS   :=  -g3 -Ofast -Wall -Wextra -Werror
LDFLAGS  := $(addprefix -L,$(dir $(LIBS)))

#******************************************************************************#
#                                  TARGETS                                     #
#******************************************************************************#

all: $(LIBFT) $(NAME)

$(LIBFT):
	make bonus -C libft/

$(NAME): obj $(OBJS)
	$(CC) $(OBJS) $(LIBFT) -o $@
	echo "Executável $@ criado com sucesso!"

obj:
	mkdir -p $(BUILD)

obj/%.o: $(SRC_P)%.c $(INCS)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	make fclean -C libft/
	$(RM) $(BUILD)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean bonus

.DEFAULT_GOAL := all

.SILENT: