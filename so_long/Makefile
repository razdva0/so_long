# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtitan <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/30 23:27:56 by mtitan            #+#    #+#              #
#    Updated: 2021/11/30 23:27:58 by mtitan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror

AR			=	ar rcs
RM			=	rm -f

MLX_DIR		=	./mlx/
HEADER		=	./so_long.h

MLX_FLAGS	=	-L./mlx -lmlx -framework OpenGL -framework Appkit

SRCS		=	main.c			ft_parsing.c		ft_split.c\
				ft_utils.c		ft_utilss.c			ft_init_img.c\
				ft_put_img.c	ft_move.c

OBJS		=	$(SRCS:.c=.o)

.c.o		:
	@$(CC) $(CFLAGS) -I $(HEADER) -o $@ -c $?

$(NAME)		:	$(OBJS)
	@make -C $(MLX_DIR)
	@$(CC) -o $(NAME) $(OBJS) -L $(MLX_DIR) -lmlx -framework OpenGL -framework Appkit

all			:	$(NAME)

clean		:
	@make -C $(MLX_DIR) clean
	@$(RM) $(OBJS)

fclean		:	clean
	@$(RM) $(NAME)

re			:	clean all

PHONY		:	all clean fclean re
