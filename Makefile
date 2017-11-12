# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jamerlin <jamerlin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/30 13:42:05 by jamerlin          #+#    #+#              #
#    Updated: 2017/10/31 12:09:01 by jamerlin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

RM = rm -rf

LIB = -L ./libft/ -lft -L ./minilibx_macos/ -lft

HEADER = -I ./includes

CC = gcc -Werror -Wextra -Wall -I./includes

MLX = -lmlx -framework OpenGL -framework AppKit

SRCS =  srcs/main.c \
        	srcs/tools.c \
            srcs/julia.c \
            srcs/mandelbrot.c \
            srcs/sierpinski.c \
			srcs/event.c \

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)	
		make -C libft/
		make -C minilibx_macos/
		$(CC) $(MLX) -o $(NAME) $(OBJS) $(LIB) $(HEADER)

all: $(NAME)

clean:
		$(RM) $(OBJS)
		make clean -C libft/
		make clean -C minilibx_macos/

fclean: clean
		$(RM) $(NAME)
		make fclean -C libft/

re: fclean all
