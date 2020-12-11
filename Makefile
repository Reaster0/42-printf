# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: earnaud <earnaud@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/07 15:42:07 by earnaud           #+#    #+#              #
#    Updated: 2020/12/11 18:40:41 by earnaud          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
CFLAGS		= -Wall -Wextra -Werror -I./includes -c
LIBFT		= ./libft/libft.a
FILES		= srcs/ft_itoa_base.c \
			  srcs/ft_printf.c \
			  srcs/ft_parsarg.c \
			  srcs/ft_conversion_int.c \
			  srcs/ft_conversion_char.c \
			  srcs/ft_conversion_string.c \
			  srcs/ft_conversion_pointer.c \
			  srcs/ft_conversion_unsign.c \
			  srcs/ft_conversion_hexa.c \
			  srcs/ft_conversion_percent.c
			  	
OBJ			= $(FILES:%.c=%.o)

all: $(NAME) 

$(LIBFT):
	@make all -C libft
	mv $(LIBFT) $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o : %.c
	gcc $(CFLAGS) -o $@ -c $< 

clean:
	rm -f $(OBJ)
	@make clean -C libft

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re bonus
