# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/21 15:04:14 by mevangel          #+#    #+#              #
#    Updated: 2023/12/10 19:16:56 by mevangel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := my_lib.a
CFLAGS := -Wall -Wextra -Werror
CC := cc

OBJ_DIR		=	./obj/

SRCS	:=	ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_strlen.c \
			ft_linelen.c \
			ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strnstr.c \
			ft_atoi.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_split.c \
			ft_strtrim.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_free_2darr.c \
			ft_read_line.c \
			ft_strjoin_gnl.c \
			ft_strjoin_free_both.c \
			get_next_line.c \
			ft_printf.c \
			ft_printf_utils.c \
			ft_error_exit.c \
			ft_err_exit_fr1_clsfd.c

OBJS		=	$(SRCS:%.c=$(OBJ_DIR)%.o)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	
fclean: clean
	@rm -f $(NAME)

re: fclean all

all: $(NAME)

.PHONY: all clean fclean re
