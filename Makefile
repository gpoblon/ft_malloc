# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpoblon <gpoblon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/02 15:03:29 by aditsch           #+#    #+#              #
#    Updated: 2018/02/08 22:02:18 by gpoblon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc.so

NAME_LINK = libft_malloc_$(HOSTTYPE).so

SRCS =	thread_safe.c \
		malloc.c \
		free.c \
		realloc.c \
		maps.c \
		blocks.c \
		utils.c \
		show_alloc_mem.c \
		show_alloc_mem_full.c \
		show_alloc_mem_hex.c \
		reallocf.c \
		# calloc.c \

INC_D	=	includes/
SRC_D	= 	srcs/
OBJ_D	=	objs/
OBJS	=	$(addprefix $(OBJ_D), $(SRCS:.c=.o))

CC		=	gcc

CFLAGS	=	-Wextra -Wall -fpic -I $(INC_D)

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(NAME_LINK)
		rm $(NAME) 2> /dev/null || true
		ln -s $(NAME_LINK) $(NAME)

$(NAME_LINK): $(OBJ_D) $(OBJS)
		$(CC) -shared $(CFLAGS) -o $(NAME_LINK) $(OBJS)

$(OBJ_D)%.o: $(SRC_D)%.c $(INC_D)/malloc.h
		$(CC) -c $< -o $@ $(CFLAGS)

$(OBJ_D):
		mkdir -p $(OBJ_D)
		mkdir -p $(dir $(OBJ_D))	

clean:
		rm -rf $(OBJ_D)

fclean: clean
		rm -fv $(NAME) $(NAME_LINK)

re: fclean all