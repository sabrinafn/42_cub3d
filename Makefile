# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/25 18:38:48 by mgonzaga          #+#    #+#              #
#    Updated: 2025/01/26 14:01:55 by mgonzaga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

LIBFT = libft/libft.a

FILES = main.c read_content.c find_map.c map_validation.c \
find_player.c wall_validation.c
OBJ = $(FILES:%.c=%.o)

all: libft $(NAME)
libft: 
	make all -C libft 

%.o: %.c 
	cc -g3 -Wall -Wextra -Werror  -c $< -o $@ 
$(NAME): $(OBJ) $(LIBFT)
	cc -g3 -Wall -Wextra -Werror $(OBJ) $(LIBFT) -o $(NAME)
fclean: clean
	rm -f $(NAME)
	make fclean -C libft 
clean: 
	rm -f $(OBJ)
	make clean -C libft 
v: all
	valgrind --leak-check=full --show-leak-kinds=all $(NAME) $(FILE)
re: fclean all

.PHONY: all fclean clean re libft