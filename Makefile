# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baboulou <baboulou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/30 22:46:58 by baboulou          #+#    #+#              #
#    Updated: 2023/05/31 00:16:42 by baboulou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
NAME_BONUS = fractol_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit
MATHFLAGS = -lm
SRCS = mandatory/fractol.c mandatory/hooks.c mandatory/inits.c mandatory/maths.c mandatory/render.c mandatory/utils.c
SRCS_BONUS = bonus/fractol_bonus.c bonus/hooks_bonus.c bonus/inits_bonus.c bonus/maths_bonus.c bonus/render_bonus.c bonus/utils_bonus.c
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
HEADER = ./mandatory/fractol.h
HEADER_BONUS = ./bonus/fractol_bonus.h

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJS) $(HEADER)
		$(CC) $(CFLAGS) ${MATHFLAGS} $(MLXFLAGS) $(OBJS) -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS) $(HEADER_BONUS)
		$(CC) $(CFLAGS) ${MATHFLAGS} $(MLXFLAGS) $(OBJS_BONUS) -o $(NAME_BONUS)

%.o: %.c $(HEADER)
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
		rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
