# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daejlee <daejlee@student.42seoul.k>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/30 13:56:42 by daejlee           #+#    #+#              #
#    Updated: 2022/04/29 16:01:25 by daejlee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
CC = gcc
LIBFT_SRC = ./libft/ft_atoi.c ./libft/ft_bzero.c ./libft/ft_calloc.c ./libft/ft_isalnum.c ./libft/ft_isalpha.c ./libft/ft_isascii.c ./libft/ft_isdigit.c ./libft/ft_isprint.c ./libft/ft_itoa.c ./libft/ft_memchr.c ./libft/ft_memcmp.c ./libft/ft_memcpy.c ./libft/ft_memmove.c ./libft/ft_memset.c ./libft/ft_putchar_fd.c ./libft/ft_putendl_fd.c ./libft/ft_putnbr_fd.c ./libft/ft_putstr_fd.c ./libft/ft_split.c ./libft/ft_strchr.c ./libft/ft_strdup.c ./libft/ft_striteri.c ./libft/ft_strjoin.c ./libft/ft_strlcat.c ./libft/ft_strlcpy.c ./libft/ft_strlen.c ./libft/ft_strmapi.c ./libft/ft_strncmp.c ./libft/ft_strnstr.c ./libft/ft_strrchr.c ./libft/ft_strtrim.c ./libft/ft_substr.c ./libft/ft_tolower.c ./libft/ft_toupper.c ./libft/ft_lstadd_back.c ./libft/ft_lstadd_front.c ./libft/ft_lstclear.c  ./libft/ft_lstdelone.c ./libft/ft_lstiter.c ./libft/ft_lstlast.c ./libft/ft_lstmap.c ./libft/ft_lstnew.c ./libft/ft_lstsize.c
LIBFT_OBJ = ft_atoi.o ft_bzero.o ft_calloc.o ft_isalnum.o ft_isalpha.o ft_isascii.o ft_isdigit.o ft_isprint.o ft_itoa.o ft_memchr.o ft_memcmp.o ft_memcpy.o ft_memmove.o ft_memset.o ft_putchar_fd.o ft_putendl_fd.o ft_putnbr_fd.o ft_putstr_fd.o ft_split.o ft_strchr.o ft_strdup.o ft_striteri.o ft_strjoin.o ft_strlcat.o ft_strlcpy.o ft_strlen.o ft_strmapi.o ft_strncmp.o ft_strnstr.o ft_strrchr.o ft_strtrim.o ft_substr.o ft_tolower.o ft_toupper.o ft_lstadd_back.o ft_lstadd_front.o ft_lstclear.o  ft_lstdelone.o ft_lstiter.o ft_lstlast.o ft_lstmap.o ft_lstnew.o ft_lstsize.o
SRC = ft_printf.c ft_write_c.c ft_write_d.c ft_write_i.c ft_write_p.c ft_write_per.c ft_write_s.c ft_write_u.c ft_write_x.c ft_write_X.c
OBJ = ft_printf.o ft_write_c.o ft_write_d.o ft_write_i.o ft_write_p.o ft_write_per.o ft_write_s.o ft_write_u.o ft_write_x.o ft_write_X.o
BONUS_SRC = 
BONUS_OBJ = 

ifdef WITH_BONUS
	OBJ_FILES = $(BONUS_OBJ)
	SRC_FILES = $(BONUS_SRC)
else
	OBJ_FILES = $(OBJ) $(LIBFT_OBJ)
	SRC_FILES = $(SRC) $(LIBFT_SRC)
endif

all : $(NAME)

$(NAME) : $(OBJ_FILES)
	ar rcs $(NAME) $(OBJ_FILES)

clean :
	rm -f $(OBJ_FILES) $(BONUS_OBJ)

fclean :
	rm -f $(OBJ_FILES) $(BONUS_OBJ) $(NAME)

re :
	$(MAKE) fclean
	$(MAKE) all

$(OBJ_FILES) : $(SRC_FILES)
	$(CC) $(CFLAGS) -c $(SRC_FILES)

bonus : $(NAME) $(BONUS_OBJ)
	make WITH_BONUS=1 $(NAME)
