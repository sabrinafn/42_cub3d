# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/20 16:00:25 by mgonzaga          #+#    #+#              #
#    Updated: 2025/03/28 16:44:24 by mgonzaga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FILES = ft_strlen.c ft_bzero.c ft_strcpy.c ft_strchr.c \
ft_strncmp.c ft_atoi.c ft_calloc.c ft_split.c get_next_line.c

OBJ = $(FILES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar -rcs $@ $^

%.o: %.c
	@gcc -Wall -Wextra -Werror -g -c $< -o $@ > /dev/null 2>&1
clean:
	@rm -f $(OBJ) > /dev/null 2>&1

fclean: clean
	@rm -f $(NAME) > /dev/null 2>&1

re: fclean all

.PHONY: all clean fclean re
