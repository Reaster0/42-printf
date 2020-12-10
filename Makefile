# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: earnaud <earnaud@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/07 15:42:07 by earnaud           #+#    #+#              #
#    Updated: 2020/12/10 18:59:52 by earnaud          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
CFLAGS		= -Wall -Wextra -Werror -I. -c
FILES		= ft_atoi.c \
			  ft_isalpha.c \
			  ft_memccpy.c \
			  ft_memmove.c \
			  ft_strlcat.c \
			  ft_strnstr.c \
			  ft_bzero.c \
			  ft_isascii.c \
			  ft_memchr.c \
			  ft_memset.c \
			  ft_strlcpy.c \
			  ft_strrchr.c \
			  ft_calloc.c \
			  ft_isdigit.c \
			  ft_memcmp.c \
			  ft_strchr.c \
			  ft_strlen.c \
			  ft_tolower.c \
			  ft_isalnum.c \
			  ft_isprint.c \
			  ft_memcpy.c \
			  ft_strdup.c \
			  ft_strncmp.c \
			  ft_toupper.c \
			  ft_substr.c \
			  ft_strjoin.c \
			  ft_strtrim.c \
			  ft_split.c \
			  ft_itoa.c \
			  ft_strmapi.c \
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
			  ft_itoa_base.c \
			  ft_printf.c \
			  ft_parsarg.c \
			  ft_conversion_int.c \
			  ft_conversion_char.c \
			  ft_conversion_string.c \
			  ft_conversion_pointer.c \
			  ft_conversion_unsign.c \
			  ft_conversion_hexa.c \
			  ft_conversion_percent.c
			  	
OBJ			= $(FILES:%.c=%.o)

all: $(NAME) 

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ): $(FILES)
	gcc $(CFLAGS) $(FILES)

clean:
	rm -f $(OBJ)
	rm -f $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
