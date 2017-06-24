# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcuer <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/04 15:45:58 by tcuer             #+#    #+#              #
#    Updated: 2017/06/24 18:47:06 by tcuer            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MKEX = clang -o

SRC = main.c ft_draw.c ft_init.c ft_hook.c ft_map.c

FLAGS = -Wall -Wextra -Werror

OBJECT = $(SRC:.c=.o)

LIBFT = ./libft/libft.a

COMP = clang -c

NAME = wolf3d

INCLUDESLIB = ./libft/includes/

all : $(NAME)

$(NAME) : $(OBJECT)
	@make -sC libft/
	@echo "Compilation Wolf3D"
	@$(MKEX) $(NAME) $(OBJECT)  ./minilibx_macos/libmlx.a -framework OpenGL -framework AppKit -L libft/ -lft
	@echo "Done"

%.o:%.c
	@$(COMP) $< -o $@ $(FLAGS) -I./ -I /usr/X11/include/ -I $(INCLUDESLIB)

clean :
	@make clean -C libft/
	@/bin/rm -f $(OBJECT)
	@echo "Object deleted"

fclean : clean
	@make fclean -C libft/
	@/bin/rm -f $(NAME)
	@echo "Folder cleanup successful"

re : fclean all
